/*
 * hotel.h  : definities en declaraties voor bestanden
 */
#include <stdio.h>
#include <string.h>

#define MAX	100
#define NLEN	6
#define LEN	14
#define HLEN	18
#define TNAAM "org.txt"
#define BNAAM "org.dat"
#define INAAM "org.ndx"

typedef struct
{
    int nr;
    char	hotel[HLEN];
    char	plaats[LEN];
    char	land[LEN];
    char	type[NLEN];
    int	aantkamers;
    float	omzet;
} Hotelinfo;

typedef struct
{
    int	index;
    char	naam[HLEN];
} Tabel;

/*
 * hieronder: externe declaraties van functies en variabelen
 */

int binzoek( Tabel[],int,Tabel);
void omvormen(void);
void lijst(void);
void indiceren(void);
void zoek(void);