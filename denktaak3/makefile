all: denktaak

denktaak: gvar.o svar.o
	cc -o denktaak gvar.o svar.o -lm

gvar.o: gvar.c gvar.h
	cc -c gvar.c

svar.o: svar.c gvar.h
	cc -c svar.c

