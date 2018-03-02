/*lijst.c*/

#include "hotel.h"

void lijst(void)
{
    FILE *fin;
    fin = fopen(BNAAM, "r");

    Hotelinfo hotelstruct;

    for(int i=0;i < LEN;i++)
    {
        fread(&hotelstruct, sizeof(hotelstruct), 1, fin);

        printf("%d %s %s %s %s %d %f\n", hotelstruct.nr,
               hotelstruct.hotel,
               hotelstruct.plaats,
               hotelstruct.land,
               hotelstruct.type,
               hotelstruct.aantkamers,
               hotelstruct.omzet);
    }

    fclose(fin);
}