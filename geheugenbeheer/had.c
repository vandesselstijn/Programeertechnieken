/*
 * had.c : allocatie en deallocatie algoritme
 */
#include <stdio.h>
#include "had.h"

int main(int argc, char *argv[])
{
	register int	n, p, waar, gevraagd;
	int mem[TOTAAL];
	char	str[LEN] ;
	char	*ptr ;

	while ( gets(str) != NULL )
	{
		switch(str[0])
		{
		case 'a' :
			gevraagd = atoi( &str[2] ) ;
			n = alloc(mem,gevraagd) ;
			break ;
		case 'd' :
			waar = strtol(&str[2], &ptr, 10);
			gevraagd = strtol(ptr+1, (char **)NULL,10);
			n = dealloc(mem,waar, gevraagd) ;
			break ;
		case 'v' :
			for (	p=0, n=0;
				p != (int)NILP ;
				p = mem[p]>>16 )
			{
				printf("%4d (%2x) : %4d %4d\n",
					p,
					p,
					mem[p]>>16,
					mem[p]&0xffff);
				n += mem[p]&0xffff ;
			}
			printf("Totaal vrij: %4d\n", n) ;
			break ;
		case 'z' :
			for (p=0; p<TOTAAL; p++)
			{
				printf("%3x:",p);
				if ( mem[p] == TOTAAL )
					printf("%8c", ' '); 
				else if (mem[p] == - TOTAAL)
					printf("  ++++++"); 
				else
					printf("%8x", mem[p]);
				printf("%c",((p+1)%6 ? ' ':'\n'));
			}
			printf("\n") ;
			break ;
		case 'i' :
			mem[0] = (1<<16)|0;
			mem[1] = (NILP<<16) | (TOTAAL-1) ;
			for(p=2; p<TOTAAL; p++ )
				mem[p] = TOTAAL ;
			break ;
		case 't' :
			for(p=1; p<TOTAAL; p++ )
				mem[p] = TOTAAL ;
			mem[0] = (11<<16)|0;
			for(p=1; p<=10; p++ )
				mem[p] = -TOTAAL ;
			mem[11] = (21<<16) | (8) ;
			for(p=19; p<=20; p++ )
				mem[p] = -TOTAAL ;
			mem[21] = (NILP<<16) | (29) ;
			break ;
		default:
			printf(	"q(uit) i(nit) z(ien) v(rij) t(test) "
				"a<aant> d<waar aant>\n");
			break ;
		case 'q' :
			exit(0);
		}
	}
}
