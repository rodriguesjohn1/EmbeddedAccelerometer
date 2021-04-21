#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>

using namespace std;

#include "DE1SoCfpga.h"
#include "PIOControl.h"

// constructor
PIOControl::PIOControl() {
      out_regvalue = 0;
      in_regValue = 0;
}

// destructor
PIOControl::~PIOControl() {
    cout<<"Closing PIOs..."<<endl;
}   

// Set the state of the PIO with the given value.
void PIOControl::WritePIOout(int value) {
    RegisterWrite(OUT_BASE, value);
    this->out_regvalue = value;
}


// Read the value in the PIO Register
int PIOControl::ReadPIOin() {
    this->in_regValue = RegisterRead(IN_BASE);
    return this->in_regValue;
}