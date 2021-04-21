#include "ADXL345.h"
#include "DE1SoChps.h"
#include "GSensor.h"
#include "DE1SoCfpga.h"
#include "PIOControl.h"
#include <stdio.h>

int main(void) {

    uint8_t devid;
    int16_t mg_per_lsb = 4;
    int16_t XYZ[3];

    // create a new instance of the sensor
    GSensor *sensor = new GSensor();

    // create a new instance of PIO
    PIOControl *pio = new PIOControl();

    // 0xE5 is read from DEVID(0x00) if I2C is functioning correctly
    sensor->ADXL345_RegRead(0x00, &devid);

    // correct  Device ID
    if (devid == 0xE5) {
        // initialize  acceleromter chip
        sensor->ADXL345_Init();

        while (1) {
            if (sensor->ADXL345_IsDataReady()) {
                sensor->ADXL345_XYZ_Read(XYZ);
                pio->WritePIOout(XYZ[0]*mg_per_lsb);
                printf("X=%d mg, Y=%d mg, Z=%d mg, Angle: %d\n", XYZ[0]*mg_per_lsb,XYZ[1]*mg_per_lsb, XYZ[2]*mg_per_lsb, pio->ReadPIOin());
            }
        }
    }
    else {
        printf("Incorrect device ID\n");
    }

    return 0;

} // end main