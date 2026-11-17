// Reads a matrix and counts the number of negative, positive, and zero elements
#include <stdio.h>

int main()
{
    int n,m,i,j,M[100][100];
    int x=0;
    int y=0;
    int z=0;

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d", &M[i][j]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            {
                if(M[i][j]>0)
                {
                    x=x+1;
                }
                else if(M[i][j]<0)
                {
                    y=y+1;
                }
                else z=z+1;
            }
    }

    printf("Numarul elementelor strict pozitive din matrice este: %d\n", x);
    printf("Numarul elementelor strict negative din matrice este: %d\n", y);
    printf("Numarul elementelor egale cu zero din matrice este: %d ", z);

    return 0;
}
