#include "DE1SoCfpga.h"

#ifndef PIOCONTROL_H
#define PIOCONTROL_H


class PIOControl: public DE1SoCfpga {
    private:
        unsigned int out_regvalue;
        unsigned int in_regValue;


    public:

        // constructor
        PIOControl();

        // destructor
        ~PIOControl();

        // Set the state of the PIO with the given value.
        void WritePIOout(int value);

        // Read the value in the PIO Register
        int ReadPIOin();


}; // end class
#endif