all : had


a.o : a.c had.h
	cc -c  a.c

d.o : d.c had.h
	cc -c d.c

had.o : had.c had.h
	cc -c  had.c

had : a.o d.o had.o
	cc -o had  a.o d.o had.o

print:
	listing a.c d.c
