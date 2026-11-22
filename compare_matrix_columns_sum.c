// Compare the sum of elements between two given columns (C1 and C2) in a matrix

#include <stdio.h>

int main()
{
    int i,j,n,m,M[100][100],C1,C2,suma1=0,suma2=0;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            {
             scanf("%d",&M[i][j]);
            }
    }

    scanf("%d%d",&C1,&C2);
    C1--; //indexare de la 0, in interiorul matricei (C1=C1-1)
    C2--;

    if(C1<0 || C1>=m) //inchidem programul daca o coloana aleasa este in afara matricei noastre
        return 1;
    if(C2<0 || C2>=m)
        return 1;

    for(i=0;i<n;i++)
        {
          suma1=suma1+M[i][C1]; //facem suma pe coloanele dorite
          suma2=suma2+M[i][C2];
        }

    if(suma1>suma2)
        printf("Suma de pe prima coloana aleasa este mai mare fata de suma de pe cea de pe a doua coloana ");
        else if(suma1<suma2)
                printf("Suma de pe prima coloana aleasa este mai mica fata de suma de pe cea de pe a doua coloana ");
                else printf("Suma de pe prima coloana aleasa este egala cu suma de pe cea de pe a doua coloana ");

    return 0;
}
