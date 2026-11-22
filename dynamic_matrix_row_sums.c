// Dynamically allocate a matrix, compute each row's sum into an array, and find the max sum row index

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,smax,k;
    int **M,*v;
    scanf("%d%d",&n,&m);

    M=(int**)malloc(n * sizeof(int*));

    if(M==NULL)
        return 1;

    for(i=0;i<n;i++)
    {
        M[i]=(int*)malloc(m * sizeof(int));

        if(M[i]==NULL)
        {
            for(j=0;j<i;j++)
                free(M[j]);
            free(M);
            return 1;
        }
    }

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&M[i][j]);

    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
            printf("%d ",M[i][j]);
    }

    v=(int*)malloc(n * sizeof(int));

    if(v==NULL)
    {
        for(i=0;i<n;i++)
            free(M[i]);
        free(M);
        return 1;
    }

    for(i=0;i<n;i++)
    {
        v[i]=0;
        for(j=0;j<m;j++)
            v[i]=v[i]+M[i][j];
    }

    smax=v[0];
    k=0;

    for(i=1;i<n;i++)
    {
        if(v[i]>smax)
        {
            smax=v[i];
            k=i;
        }
    }

    printf("\n");
    printf("\nVectorul cu suma liniilor matricei este: ");

    for(i=0;i<n;i++)
        printf("%d ",v[i]);

    printf("\n");
    printf("Indexul liniei cu suma maxima este: %d ",k);

    free(v);

    for(i=0;i<n;i++)
        free(M[i]);

    free(M);

    return 0;
}
