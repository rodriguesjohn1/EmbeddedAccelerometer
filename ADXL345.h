#ifndef ADXL345_H
#define ADXL345_H


/* Bit values in BW_RATE                        */
/* Expresed as output data rate */
const unsigned int XL345_RATE_3200       = 0x0f;
const unsigned int XL345_RATE_1600       = 0x0e;
const unsigned int XL345_RATE_800        = 0x0d;
const unsigned int XL345_RATE_400        = 0x0c;
const unsigned int XL345_RATE_200        = 0x0b;
const unsigned int XL345_RATE_100        = 0x0a;
const unsigned int XL345_RATE_50         = 0x09;
const unsigned int XL345_RATE_25         = 0x08;
const unsigned int XL345_RATE_12_5       = 0x07;
const unsigned int XL345_RATE_6_25       = 0x06;
const unsigned int XL345_RATE_3_125      = 0x05;
const unsigned int XL345_RATE_1_563      = 0x04;
const unsigned int XL345_RATE__782       = 0x03;
const unsigned int XL345_RATE__39        = 0x02;
const unsigned int XL345_RATE__195       = 0x01;
const unsigned int XL345_RATE__098       = 0x00;

/* Bit values in DATA_FORMAT                                            */

/* Register values read in DATAX0 through DATAZ1 are dependant on the 
   value specified in data format.  Customer code will need to interpret
   the data as desired.                                                 */
const unsigned int XL345_RANGE_2G             = 0x00;
const unsigned int XL345_RANGE_4G             = 0x01;
const unsigned int XL345_RANGE_8G             = 0x02;
const unsigned int XL345_RANGE_16G            = 0x03;
const unsigned int XL345_DATA_JUST_RIGHT      = 0x00;
const unsigned int XL345_DATA_JUST_LEFT       = 0x04;
const unsigned int XL345_10BIT                = 0x00;
const unsigned int XL345_FULL_RESOLUTION      = 0x08;
const unsigned int XL345_INT_LOW              = 0x20;
const unsigned int XL345_INT_HIGH             = 0x00;
const unsigned int XL345_SPI3WIRE             = 0x40;
const unsigned int XL345_SPI4WIRE             = 0x00;
const unsigned int XL345_SELFTEST             = 0x80;

/* Bit values in INT_ENABLE, INT_MAP, and INT_SOURCE are identical
   use these bit values to read or write any of these registers.        */
const unsigned int XL345_OVERRUN              = 0x01;
const unsigned int XL345_WATERMARK            = 0x02;
const unsigned int XL345_FREEFALL             = 0x04;
const unsigned int XL345_INACTIVITY           = 0x08;
const unsigned int XL345_ACTIVITY             = 0x10;
const unsigned int XL345_DOUBLETAP            = 0x20;
const unsigned int XL345_SINGLETAP            = 0x40;
const unsigned int XL345_DATAREADY            = 0x80;

/* Bit values in POWER_CTL                        */
const unsigned int XL345_WAKEUP_8HZ           = 0x00;
const unsigned int XL345_WAKEUP_4HZ           = 0x01;
const unsigned int XL345_WAKEUP_2HZ           = 0x02;
const unsigned int XL345_WAKEUP_1HZ           = 0x03;
const unsigned int XL345_SLEEP                = 0x04;
const unsigned int XL345_MEASURE              = 0x08;
const unsigned int XL345_STANDBY              = 0x00;
const unsigned int XL345_AUTO_SLEEP           = 0x10;
const unsigned int XL345_ACT_INACT_SERIAL     = 0x20;
const unsigned int XL345_ACT_INACT_CONCURRENT = 0x00;

/* Register Addresses 
 * - Rest value = 0x00 unless indicated otherwise
 * - Refer to ADXL345 Datasheet for register descriptions
 */
const unsigned int ADXL345_REG_DEVID       		= 0x00; // R: E5
const unsigned int ADXL345_REG_THRESH_TAP   	= 0x1D;  // R/W
const unsigned int ADXL345_REG_OFSX   			= 0x1E;  // R/W
const unsigned int ADXL345_REG_OFSY   			= 0x1F;  // R/W
const unsigned int ADXL345_REG_OFSZ   			= 0x20;  // R/W
const unsigned int ADXL345_REG_DUR   			= 0x21;  // R/W
const unsigned int ADXL345_REG_LATENT   		= 0x22;  // R/W
const unsigned int ADXL345_REG_WINDOW   		= 0x23;  // R/W
const unsigned int ADXL345_REG_THRESH_ACT   	= 0x24;  // R/W
const unsigned int ADXL345_REG_THRESH_INACT 	= 0x25;  // R/W
const unsigned int ADXL345_REG_TIME_INACT   	= 0x26;  // R/W
const unsigned int ADXL345_REG_ACT_INACT_CTL 	= 0x27;  // R/W
const unsigned int ADXL345_REG_THRESH_FF   		= 0x28;  // R/W
const unsigned int ADXL345_REG_TIME_FF   		= 0x29;  // R/W
const unsigned int ADXL345_REG_TAP_AXES   		= 0x2A;  // R/W
const unsigned int ADXL345_REG_ACT_TAP_STATUS   = 0x2B;  // R
const unsigned int ADXL345_REG_BW_RATE     		= 0x2C; 	// R/W: 0x0A
const unsigned int ADXL345_REG_POWER_CTL   		= 0x2D;  // R/W
const unsigned int ADXL345_REG_INT_ENABLE  		= 0x2E;  // R/W
const unsigned int ADXL345_REG_INT_MAP     		= 0x2F;  // R/W
const unsigned int ADXL345_REG_INT_SOURCE  		= 0x30;  // R: 0x02
const unsigned int ADXL345_REG_DATA_FORMAT 		= 0x31;  // R/W
const unsigned int ADXL345_REG_DATAX0      		= 0x32;  // R
const unsigned int ADXL345_REG_DATAX1      		= 0x33;  // R
const unsigned int ADXL345_REG_DATAY0      		= 0x34;  // R
const unsigned int ADXL345_REG_DATAY1      		= 0x35;  // R
const unsigned int ADXL345_REG_DATAZ0      		= 0x36;  // R
const unsigned int ADXL345_REG_DATAZ1      		= 0x37;  // R
const unsigned int ADXL345_REG_FIFO_CTL    		= 0x38;	// R/W
const unsigned int ADXL345_REG_FIFO_STATUS    	= 0x39; // R

#endif /*ADXL345_H*/
