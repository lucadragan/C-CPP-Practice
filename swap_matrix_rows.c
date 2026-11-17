// Function that swaps the elements of two given rows l1 and l2 in a matrix
#include <stdio.h>

void schimbaLinii(int a[][10],int n,int m,int l1,int l2)
{
    int j,aux;

    for(j=0;j<m;j++)
        {
        aux=a[l1][j];
        a[l1][j]=a[l2][j];
        a[l2][j]=aux;
        }
}

int main()
{
    int i,j,n,m,a[10][10],l1,l2;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }

    scanf("%d%d",&l1,&l2); //indexarea se face de la 0, astfel linia 1 va fi scrisa ca linia 0 in program

    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
            printf("%d ", a[i][j]);
    }

    printf("\n");

    schimbaLinii(a,n,m,l1,l2);
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
            printf("%d ", a[i][j]);
    }

    return 0;
}
