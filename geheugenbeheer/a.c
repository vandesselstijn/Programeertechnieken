#include "had.h"

int alloc(int mem[],int gevraagd)
{
	int geheugenpos = 0;
	int beschikbaar = 1;
	int tempmem = 0;
	int prevmem = 0;
	int nextmem = 0;
	int i;

	printf("alloc\n");
	printf("gevraagd geheugen: %i\n", gevraagd);
	
	while(beschikbaar)
	{

		printf("Element zit op positie %x", geheugenpos);
		printf(" Ruimte is %x\n", mem[geheugenpos]&0xffff);
	
		
		printf("gevraagd = %x\n", gevraagd);
		printf("ruimte  = %x\n", (mem[geheugenpos]&0xffff));
		
		
		if((mem[geheugenpos]&0xffff) > gevraagd)
		{
			printf("Deze locatie is groot genoeg\n");
			
			tempmem = mem[geheugenpos];
			
			
			for(i=geheugenpos;i < geheugenpos+gevraagd; i++)
			{
				mem[i] = - TOTAAL;
				beschikbaar = 0;
			}
			mem[i] = tempmem - gevraagd;
			mem[prevmem] = (0xffff0000 & (geheugenpos+gevraagd << 16) ) | (0x0000ffff & mem[prevmem]);  //vorige aanpassen
						
		}
		if((mem[geheugenpos]&0xffff) == gevraagd)
		{
			printf("Deze locatie is exact groot genoeg\n");
			
			tempmem = mem[geheugenpos];
			
			for(i=geheugenpos;i <= geheugenpos+gevraagd; i++)
			{
				mem[i] = - TOTAAL;
				beschikbaar = 0;
			}
			//vorige naar volgende laten wijzen
			mem[prevmem] = (0xffff0000 & tempmem) | (0x0000ffff & mem[prevmem]);  //vorige aanpassen
		}
		else
		{
			prevmem = geheugenpos;
			printf("Deze locatie is niet groot genoeg\n");
		}
		
		geheugenpos = mem[geheugenpos]>>16;
		if(geheugenpos == NILP)
		{
			beschikbaar = 0;
			printf("Niet genoeg plaats\n");
		}
	}  // ik ben stijn, en ik kan niet uitloggen
	return 0;
}
