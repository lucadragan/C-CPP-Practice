// Reads an n x m matrix and prints the sum of elements for each individual row
#include <stdio.h>

int main()
{
    int n,m,i,j,M[100][100];
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d", &M[i][j]);
    }

    for(i=0;i<n;i++)
    {
       int suma=0; //suma este resetata mereu la 0, resetam suma pentru fiecare linie noua
       for(j=0;j<m;j++)
            {suma=suma+M[i][j];} //adunam elementele de pe linia curenta
       printf("\n");
       printf("%d ", suma);
    }

    return 0;
}
