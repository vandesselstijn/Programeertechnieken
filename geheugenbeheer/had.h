/*
 * had.h : allocatie en deallocatie w: deklaraties en definities
 */
#include <stdio.h>

#define	TOTAAL 	50 
#define NILP	-1 
#define LEN		40 

int alloc(int mem[],int gevraagd);
int dealloc(int mem[],int waar, int gevraagd);
