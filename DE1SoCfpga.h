#ifndef DE1SOCFPGA_H
#define DE1SOCFPGA_H

using namespace std;

// Physical base address of FPGA Devices 
const unsigned int LW_BRIDGE_BASE 	= 0xFF200000;  // Base offset 

// Length of memory-mapped IO window 
const unsigned int LW_BRIDGE_SPAN 	= 0x00005000;  // Address map size

const unsigned int OUT_BASE         = 0x00000020;   // PIO output
const unsigned int IN_BASE          = 0x00000040;   // PIO input

class DE1SoCfpga {
    char *pBase;
    int fd;

    public:

        // constructor
        DE1SoCfpga();
        // destructor
        ~DE1SoCfpga();

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