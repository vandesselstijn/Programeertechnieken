/*txtdat.c*/

#include "hotel.h"

void omvormen(void)
{
    FILE *fin;
    FILE *fuit;

    fin = fopen(TNAAM, "r");
    fuit = fopen(BNAAM, "w");

    Hotelinfo hotelstruct;
    int hotelnummer = 0;

    while( fscanf(fin, "%s", hotelstruct.type) != EOF)
    {
        hotelstruct.nr = hotelnummer;
        hotelnummer++;

        fscanf(fin, "%s", hotelstruct.hotel);
        fscanf(fin, "%s", hotelstruct.plaats);
        fscanf(fin, "%d", &hotelstruct.aantkamers);
        fscanf(fin, "%f", &hotelstruct.omzet);
        fscanf(fin, "%s", hotelstruct.land);

        printf("%d %s %s %s %s %d %f\n", hotelstruct.nr,
                                hotelstruct.hotel,
                                hotelstruct.plaats,
                                hotelstruct.land,
                                hotelstruct.type,
                                hotelstruct.aantkamers,
                                hotelstruct.omzet);

        fwrite(&hotelstruct, sizeof(hotelstruct), 1, fuit);
    }

    fclose(fin);
    fclose(fuit);
}