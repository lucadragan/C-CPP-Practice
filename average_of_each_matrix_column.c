// Calculates and prints the arithmetic mean of elements for each column of a matrix
#include <stdio.h>

int main()
{
    int n,m,i,j,M[100][100];
    float media;

    scanf("%d%d", &n,&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d", &M[i][j]);
    }

    for(j=0;j<m;j++)
    {
        int suma=0;
        for(i=0;i<n;i++)
        {
            suma=suma+M[i][j];
        }
        media= (float)suma/n;
        printf("%.2f\n", media);
    }

    return 0;
}
