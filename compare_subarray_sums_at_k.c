// Compares the two sums of array elements delimited by a given position K
#include <stdio.h>

int main()
{
    int n,i,v[100],k;
    int S1=0;
    int S2=0;

    scanf("%d", &n);
    scanf("%d", &k);

    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }

    for(i=0;i<n;i++)
    {
        if(i<=k-1)
            S1=S1+v[i];
        else S2=S2+v[i];
    }

    if(S1>S2)
       printf("Suma elementelor pana la pozitia %d din vector este mai mare fata de suma elementelor de dupa aceasta pozitie ",k);
    else if(S1<S2)
       printf("Suma elementelor pana la pozitia %d din vector este mai mica fata de suma elementelor de dupa aceasta pozitie ",k);
    else
        printf("Suma elementelor pana la pozitia %d din vector este egala cu suma elementelor de dupa aceasta pozitie ",k);

    return 0;
}




