#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <cmath>
#include <iostream>
#include "DE1SoChps.h"
#include "GSensor.h"
using namespace std;
 
// Configure I2C Pin Multiplexer to use I2C for ADXL345.
void GSensor::PinmuxConfig() {
    
    RegisterWrite(PIN_MUX_GEN_IO7, 1);
    RegisterWrite(PIN_MUX_GEN_IO8, 1);
    RegisterWrite(PIN_MUX_I2C0USEFPGA, 0);

}

// Configure I2C0 for communication with ADXL345
void GSensor::I2C0_Init() {

    // Abort any ongoing transmits and disable I2C0.
    RegisterWrite(I2C0_ENABLE, 2);

    // Wait until I2C0 is disabled
    while((RegisterRead(I2C0_ENABLE_STATUS) & 0x1) == 1) {}

    // Configure the config reg with the desired setting (act as10
    // a master, use 7bit addressing, fast mode (400kb/s)).
    RegisterWrite(I2C0_CON, 0x65);

    // Set target address (disable special commands, use 7bit addressing)
    RegisterWrite(I2C0_TAR, 0x53);


    // Set SCL high/low counts (Assuming default 100MHZ clock input to
    // I2C0 Controller)
    // The minimum SCL high period is 0.6us, and the minimum SCL lowperiod is 1.3us,
    // However, the combined period must be 2.5us or greater, so add 0.3usto each.
    RegisterWrite(I2C0_FS_SCL_HCNT, 60 + 30); // 0.6us + 0.3us
    RegisterWrite(I2C0_FS_SCL_LCNT, 130 + 30);  // 1.3us + 0.3us
     
    // Enable the controller
    RegisterWrite(I2C0_ENABLE, 1);

    // Wait until controller is powered on
    while((RegisterRead(I2C0_ENABLE_STATUS) & ~0x1) == 0) {}

}

// Constructor Initializes Pin Multiplexer I2C0
GSensor::GSensor() {
   this->PinmuxConfig(); 
   this->I2C0_Init();
   //this->ADXL345_Init();
}  

// Destructor to finalize G-Sensor module
// Does nothing other than print a finalizing message
GSensor::~GSensor() {
    cout<<"GSensor Destroyed"<<endl;
}

// Prototypes for functions used to configure ADXL345
void GSensor::ADXL345_Init() {
    // +- 16g range, full resolution
    ADXL345_RegWrite(ADXL345_REG_DATA_FORMAT, XL345_RANGE_16G | XL345_FULL_RESOLUTION);

    // Output Data Rate: 200Hz
    ADXL345_RegWrite(ADXL345_REG_BW_RATE, XL345_RATE_200);

    // The DATA_READY bit is not reliable. It is updated at a much higherrate than the Data Rate
    // Use the Activity and Inactivity interrupts as indicators for newdata.
    ADXL345_RegWrite(ADXL345_REG_THRESH_ACT, 0x04); //activity threshold
    ADXL345_RegWrite(ADXL345_REG_THRESH_INACT, 0x02); //inactivity
    ADXL345_RegWrite(ADXL345_REG_TIME_INACT, 0x02); //time for inactivity
    ADXL345_RegWrite(ADXL345_REG_ACT_INACT_CTL, 0xFF); //Enables ACcoupling for thresholds
    ADXL345_RegWrite(ADXL345_REG_INT_ENABLE, XL345_ACTIVITY | XL345_INACTIVITY); //enable interrupts
    
    // stop measure
    ADXL345_RegWrite(ADXL345_REG_POWER_CTL, XL345_STANDBY);

    // start measure
    ADXL345_RegWrite(ADXL345_REG_POWER_CTL, XL345_MEASURE);
}

// Read value from internal register at address
void GSensor::ADXL345_RegRead(uint8_t address, uint8_t *value) {
    // Send reg address (+0x400 to send START signal)
    RegisterWrite(I2C0_DATA_CMD, address + 0x400);

    // Send read signal
    RegisterWrite(I2C0_DATA_CMD, 0x100);

    // Read the response (first wait until RX buffer contains data)
    while(RegisterRead(I2C0_RXFLR) == 0) {}
    *value = RegisterRead(I2C0_DATA_CMD);

}

// Write value to internal register at address
void GSensor::ADXL345_RegWrite(uint8_t address, uint8_t value) {
    // Send reg address (+0x400 to send START signal)
    RegisterWrite(I2C0_DATA_CMD, address + 0x400);

    // Send value
    RegisterWrite(I2C0_DATA_CMD, value);

}

// Reads values from multiple internal registers
void GSensor::ADXL345_RegMultiRead(uint8_t address, uint8_t values[], uint8_t len) {
    // Send reg address (+0x400 to send START signal)
    RegisterWrite(I2C0_DATA_CMD, address + 0x400);

    // Send read signal len times
    for (int i = 0; i < len; i++) {
        RegisterWrite(I2C0_DATA_CMD, 0x100);
    }

    // Read the bytes
    int nth_byte = 0;
    while (len) {
        if (RegisterRead(I2C0_RXFLR) > 0) { 
            values[nth_byte] = RegisterRead(I2C0_DATA_CMD);
            nth_byte++;
            len--;
        }
    }
}

// Read acceleration data of all three axes
//void GSensor::ADXL345_XYZ_Read(int16_t szData16[3], int16_t mg_per_lsb) {
void GSensor::ADXL345_XYZ_Read(int16_t szData16[3]) {
    uint8_t szData8[6];
    ADXL345_RegMultiRead(0x32, (uint8_t*)&szData8, sizeof(szData8));

    szData16[0] = (szData8[1] << 8) | szData8[0];
    szData16[1] = (szData8[3] << 8) | szData8[2];
    szData16[2] = (szData8[5] << 8) | szData8[4];
}

// Return true if there is new data
bool GSensor::ADXL345_IsDataReady() {
    bool bReady = false;
    uint8_t data8;

    ADXL345_RegRead(ADXL345_REG_INT_SOURCE, &data8);
    if (data8 & XL345_ACTIVITY) {
        bReady = true;
    }   
    return bReady;
}