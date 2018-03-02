//Een gegeven array a[] opgevuld met n integers en zoeken naar x

#include "hotel.h"

int binzoek( Tabel a[],int n,Tabel x) {
    int midden, links = 0, rechts = n - 1;

    if (strcmp(x.naam, a[links].naam) <= 0 || n==0)
        return 0;
    if (strcmp(x.naam,a[rechts].naam) > 0)
        return n;
    while ( rechts != links )
    {
        midden = ( links + rechts) /2;
        if (strcmp(x.naam,a[midden].naam) == 0)
            return midden;
        if ( strcmp(x.naam,a[midden].naam) > 0)
            links = midden + 1;
        else
            rechts = midden;
    }
    return links;
}