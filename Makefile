output: GSensorMain.o DE1SoChps.o GSensor.o DE1SoCfpga.o PIOControl.o
		g++ GSensorMain.o DE1SoChps.o GSensor.o DE1SoCfpga.o PIOControl.o -o output

GSensorMain.o: GSensorMain.cpp
		g++ -g -Wall -c GSensorMain.cpp

DE1SoChps.o:	DE1SoChps.cpp DE1SoChps.h
				g++ -g -Wall -c DE1SoChps.cpp

GSensor.o:	GSensor.cpp GSensor.h 
				g++ -g -Wall -c GSensor.cpp

DE1SoCfpga.o:	DE1SoCfpga.cpp DE1SoCfpga.h
				g++ -g -Wall -c DE1SoCfpga.cpp

PIOControl.o:	PIOControl.cpp PIOControl.h
				g++ -g -Wall -c PIOControl.cpp

clean:
		rm *.o output