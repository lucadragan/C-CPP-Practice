// Checks if a 1D array is symmetric (palindromic) by comparing elements from both ends toward the middle
#include <stdio.h>

int main()
{
    int n,i,v[100];
    int k=1;
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }

    for(i=0;i<n/2;i++) //mergem mai bine pana la jumatatea vectorului pentru eficientizare, chiar daca ar fi mers si pentru i<n simplu
    {
        if(v[i]!=v[(n-1)-i])
           {
               k=0; //k este folosit pe post de stegulet
               break; //oprire rapida
           }
    }

    if(k==1)
        {
        printf("Vectorul este simetric.");
        }
        else
        {
            printf("Vectorul este nesimetric.");
        }

    return 0;
}
