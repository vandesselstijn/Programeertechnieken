/*zoek.c*/

#include "hotel.h"

void zoek(void)
{
    FILE *fin;

    fin = fopen(INAAM, "r");

    Tabel tabelstruct[MAX];
    Tabel temptabel;
    int result;

    fread(&tabelstruct, sizeof(tabelstruct), 1, fin);

    printf("Geef een zoekterm in: \n");
    scanf("%s%*c", temptabel.naam);

    printf("U gaf volgende zoekterm op: %s\n", temptabel.naam);


    result = binzoek(tabelstruct,LEN,temptabel);
    printf("Functie gaf volgend resultaat terug: %d\n", result);

    if(strcmp(temptabel.naam, tabelstruct[result].naam)==0)
    {
        printf("Element %s is gevonden op index %d\n", temptabel.naam, result);
    }
    else
    {
        printf("U zoekopdracht kon niet worden gevonden\n");
    }


    fclose(fin);
}