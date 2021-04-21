#ifndef DE1SOCHPS_H
#define DE1SOCHPS_H

using namespace std;

/* Cyclone V HPS devices */
const unsigned int HPS_BRIDGE_BASE       = 0xFF700000;  // base
const unsigned int HPS_BRIDGE_SPAN       = 0x006FFFFF;  // span


/* I2C0 Peripheral Registers*/
const unsigned int I2C0_BASE             = 0x00504000;      // I2C0 Base Address
const unsigned int I2C0_CON              = 0x00504000;      // Control Register
const unsigned int I2C0_TAR              = 0x00504004;  // Target Address Register 0xFFC04004
const unsigned int I2C0_DATA_CMD         = 0x00504010;  // Tx Rx Data and Command Register 0xFFC04010
const unsigned int I2C0_FS_SCL_HCNT      = 0x0050401C; // Fast SpdClock SCL HCNT Register 0xFFC0401C
const unsigned int I2C0_FS_SCL_LCNT      = 0x00504020;  // Fast Spd Clock SCL LCNT Register 0xFFC04020
const unsigned int I2C0_CLR_INTR         = 0x00504040;  // Combined and Individual Interrupt Register 0xFFC04040
const unsigned int I2C0_ENABLE           = 0x0050406C;  // Enable Register
const unsigned int I2C0_TXFLR            = 0x00504074;  // Transmit FIFO Level Register 0xFFC04074
const unsigned int I2C0_RXFLR            = 0x00504078;  // Receive FIFO Level Register 0xFFC04078
const unsigned int I2C0_ENABLE_STATUS    = 0x00504070 ;   // Enable Status Register 0xFFC04070

// The Pin Multiplexer selection
const unsigned int PIN_MUX_GEN_IO7       = 0x0060849C; // GENERALIO7 reg offset 0xFFD0849C
const unsigned int PIN_MUX_GEN_IO8       = 0x006084A0; // GENERALIO8 reg offset 0xFFD084A0
const unsigned int PIN_MUX_GPLMUX55      = 0x006086B0; // GPLMUX55 reg offset 0xFFD086B0
const unsigned int PIN_MUX_GPLMUX56      = 0x006086B4; // GPLMUX56 reg offset 0xFFD086B4
const unsigned int PIN_MUX_I2C0USEFPGA   = 0x00608704; // I2C0USEFPGA  reg offset 0xFFD08704


// span 
const unsigned int gpio1_base            = 0x00009000;
const unsigned int gpio1_dr_offset       = 0x00009000;
const unsigned int gpio1_ddr_offset      = 0x00009004;
const unsigned int gpio1_debounce_offset = 0x00009048; 
const unsigned int gpio1_ext_port_offset = 0x00009050;

/* HPS timer registers */
const unsigned int timer0_load_reg       = 0x00508000;
const unsigned int timer0_curr_val_reg   = 0x00508004;
const unsigned int timer0_control_reg    = 0x00508008;
const unsigned int timer0_eoi_reg        = 0x0050800C;
const unsigned int timer0_int_stat_reg   = 0x005080A0;





class DE1SoChps {
    char *pBase;
    int fd;

    public:

        DE1SoChps();

        ~DE1SoChps();

        /** 
         * Write a 4-byte value at the specified general-purpose I/O location. 
         * @param reg_offset	Offset where device is mapped. 
         * @param value	    Value to be written. 
         */ 
        void RegisterWrite(unsigned int reg_offset, int value);

        /** 
         * Read a 4-byte value from the specified general-purpose I/O location.  
         * @param offset	Offset where device is mapped. 
         * @return		Value read. 
         */ 
        int RegisterRead(unsigned int reg_offset);


};
#endif