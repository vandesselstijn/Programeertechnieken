#include "had.h"

int dealloc(int mem[],int waar, int gevraagd)
{
	int check_scope_ok = 0;
	int geheugenpos = 0;
	int prevmem = 0;
	int nextmem = 0;
    int i;

	printf("Dealloc\n");
	printf("gevraagd geheugen: %i\n", gevraagd);
	printf("waar in geheugen: %i\n", waar);
	
	printf("\nWe willen dealloceren op positie %i\n", waar);
		
	while(!check_scope_ok)
	{
		printf("mem[geheugenpos] = %x\n", mem[geheugenpos]);
			
		prevmem = geheugenpos;
		geheugenpos = mem[geheugenpos]>>16;
		nextmem = geheugenpos;
		
		printf("Prevmem: %i Nextmem: %i\n", prevmem,nextmem);
			
		if(geheugenpos == NILP)
		{
			check_scope_ok = 1;
			printf("Laatste element gevonden\n");
		}
			
		if(waar > prevmem && waar < nextmem)
		{
			check_scope_ok = 1;
			printf("scope is gevonden\n");
		}		
	}
	
	
	
	printf("waar: %i nextmem: %i prevmem: %i gevraagd: %i prevmem_l: %i nextmem_l: %i\n", waar, nextmem, prevmem, gevraagd,(mem[prevmem] & 0x0000ffff),(mem[nextmem] & 0x0000ffff));
	
	if(waar == nextmem - gevraagd && waar == prevmem + (mem[prevmem] & 0x0000ffff))//tussenin situatie
	{
		printf("tussen in situatie\n");
		for(i=waar;i < waar+gevraagd; i++)
		{
			mem[i] = TOTAAL; 
		}
		mem[prevmem] = 0xffff0000 & mem[nextmem] | (0x0000ffff & mem[nextmem]) + (mem[prevmem] & 0x0000ffff) + gevraagd;
		mem[nextmem] = TOTAAL;
	}
	
	else if(waar == nextmem - gevraagd)//aasluitende blokken(voor een bestaande)
	{
		printf("Aaneensluitende blokken voor elkaar\n");
		mem[waar] = 0xffff0000 & mem[nextmem] | 0x0000ffff & (gevraagd + (mem[nextmem] & 0x0000ffff));
		mem[nextmem] = TOTAAL;
		for(i=waar+1;i < waar+gevraagd; i++)
		{
			mem[i] = TOTAAL; 
		}
		mem[prevmem] = 0xffff0000 & (waar << 16) | 0x0000ffff & mem[prevmem];
		return 0;
	}
	
	
	else if(waar == prevmem + gevraagd)//aasluitende blokken(na een bestaande)
	{
		printf("Aaneensluitende blokken na elkaar\n");
		for(i=waar;i < waar+gevraagd; i++)
		{
			mem[i] = TOTAAL; 
		}
		mem[prevmem] = mem[prevmem] + gevraagd;
	}

	
	else //basis situatie
	{
		printf("Dit is de normale situatie\n");
		for(i=waar;i < waar+gevraagd; i++)
		{
			mem[i] = TOTAAL; 		
		}
		//beschrijving vd brijgemaakte block maken
		//dit moet de pos vd volgende block zijn en de vrijgemaakte ruimte
		mem[waar] = 0xffff0000 & mem[prevmem] | 0x0000ffff & gevraagd;
		mem[prevmem] = 0xffff0000 & (waar << 16) | 0x0000ffff & mem[prevmem]; 
	}

	return 0;
}
