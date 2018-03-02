/*index.c*/

#include "hotel.h"

void insert(Tabel array[], int index, Tabel temp)
{
    for(int c = MAX-2; c >= index; c--) //99 is laatste element dus mogen we maar gaan tot 98 + 1
        array[c+1] = array[c];

    array[index] = temp;
}

void indiceren(void)
{
    FILE *fin;
    FILE *fuit;

    fin = fopen(BNAAM, "r");
    fuit = fopen(INAAM, "w");

    Hotelinfo hotelstruct;
    Tabel tabelstruct[MAX];
    Tabel temptabel;
    int index;

    for(int i=0;i < LEN;i++)
    {
        fread(&hotelstruct, sizeof(hotelstruct), 1, fin);

        temptabel.index=i;
        stpcpy(temptabel.naam,hotelstruct.hotel);

        index = binzoek(tabelstruct,i,temptabel);
        insert(tabelstruct,index,temptabel);

        printf("\nAantal interaties:%d\n", i);
        for(int j=0; j<=i; j++)
            printf("%d %s\n", tabelstruct[j].index, tabelstruct[j].naam);

    }

    fwrite(&tabelstruct, sizeof(tabelstruct), 1, fuit);


    fclose(fuit);
    fclose(fin);
}