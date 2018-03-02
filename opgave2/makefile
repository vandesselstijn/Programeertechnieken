all: hotel

hotel: hotel.o txtdat.o
    gcc hotel.o txtdat.o -o hotel

hotel.o: hotel.c hotel.h
    gcc -c hotel.c hotel.h

txtdat.o: txtdat.c hotel.h
    gcc -c txtdat.c hotel.h

clean:
    rm *o hotel
