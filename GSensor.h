// GSensor.h 
// Process accelerometer input from from the DE1-SoC
// Reads the XYZ accelerometer data from ADXL345 via the I2C0 line

#ifndef GSENSOR_H
#define GSENSOR_H

// project includes
#include <stdint.h>
#include "ADXL345.h"
#include "DE1SoChps.h"

class GSensor : public DE1SoChps {

    private: 
        // Configure I2C Pin Multiplexer to use I2C for ADXL345.
        void PinmuxConfig();

        // Configure I2C0 for communication with ADXL345
        void I2C0_Init();

    public:

        // Constructor Initializes Pin Multiplexer I2C0
        GSensor(); 

        // Destructor to finalize G-Sensor module
        // Does nothing other than print a finalizing message
        ~GSensor(); 

        // Prototypes for functions used to configure ADXL345
        void ADXL345_Init();

        // Read value from internal register at address
        void ADXL345_RegRead(uint8_t address, uint8_t *value);

        // Write value to internal register at address
        void ADXL345_RegWrite(uint8_t address, uint8_t value);

        // Reads values from multiple internal registers
        void ADXL345_RegMultiRead(uint8_t address, uint8_t values[], uint8_t len);

        // Read acceleration data of all three axes
        //void ADXL345_XYZ_Read(int16_t szData16[3], int16_t mg_per_lsb);
        void ADXL345_XYZ_Read(int16_t szData16[3]);

        // Return true if there is new data
        bool ADXL345_IsDataReady();

};

#endif