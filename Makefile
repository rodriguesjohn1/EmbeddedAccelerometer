# Makefile for projectFile

projectExe: GSensorMain.o DE1SoChps.o GSensor.o
	g++ -std=c++11 GSensorMain.o DE1SoChps.o GSensor.o -o projectExe

GSensorMain.o: GSensorMain.cpp DE1SoChps.h GSensor.h
	g++ -g -Wall -c GSensorMain.cpp

DE1SoChps.o: DE1SoChps.cpp DE1SoChps.h
	g++ -g -Wall -c DE1SoChps.cpp

GSensor.o: GSensor.cpp GSensor.h
	g++ -g -Wall -c GSensor.cpp

clean:
	rm -r GSensorMain.o DE1SoChps.o GSensor.o projectExe



