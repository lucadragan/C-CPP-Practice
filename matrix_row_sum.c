// Function that returns the sum of elements on a given row k of a matrix
#include <stdio.h>

int sumalinie(int M[][100],int n, int m,int k)
{
    int j,suma=0;
    for(j=0;j<m;j++)
    {
        suma=suma+M[k][j];
    }
    return suma;
}

int main()
{
    int i,j,n,m,M[100][100],k,x;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&M[i][j]);
    }
    scanf("%d",&k);
    while(k<0 || k>=n) //nu este neaparat de pus in cod, in cerinta specificandu-se clar ca k este indexat: 0<=k<n si este linia dorita

    {
        printf("Introduceti alt numar, intre 0 inclusiv si n fara acesta din urma ");
        scanf("%d",&k);
    }
    x=sumalinie(M,n,m,k);
    printf("Suma elementelor de pe linia %d este %d ",k,x); //k este indexat: 0<=k<n si este linia dorita

    return 0;
}
