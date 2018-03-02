/* Oplossen van oef hotels*/
/* Stijn Van Dessel */

#include "hotel.h"

int main(int argc,char * argv[])
{
    char keuzechar;
    int exit = 0;

    while(exit != 1) {
        printf("\nMENU\n");
        printf("\t1.Omvormen\n");
        printf("\t2.Lijst\n");
        printf("\t3.Indiceren\n");
        printf("\t4.Zoeken\n");
        printf("\t5.Exit\n");
        printf("Maak u keuze: ");

        scanf("%c%*c", &keuzechar);

        switch (keuzechar) {
            case '1':
                printf("U koos voor: Omvormen\n");
                omvormen();
                break;
            case '2':
                printf("U koos voor: Lijst\n");
                lijst();
                break;
            case '3':
                printf("U koos voor: Indiceren\n");
                indiceren();
                break;
            case '4':
                printf("U koos voor: Zoeken\n");
                zoek();
                break;
            case '5':
                printf("U koos voor: exit\n");
                exit = 1;
                break;
            default:
                printf("Error! U gaf een verkeerde keuze op\n");
        }
    }
    return 0;
}