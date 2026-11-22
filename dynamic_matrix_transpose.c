// Dynamically allocate a matrix A (n x m) and construct its transpose into a dynamically allocated matrix B (m x n)

//Cititi o matrice A, alocata dinamic, cu n linii si m coloane. Alocati o matrice B cu m linii si n coloane si construiti transpusa matricei A, conform relatiei : B[j][i] = A[i][j]
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j;
    int **A,**B;
    scanf("%d%d",&n,&m);

    A=(int**)malloc(n * sizeof(int*));
    B=(int**)malloc(m * sizeof(int*));

    if(A==NULL || B==NULL)
    {
        free (A);
        free (B);
        return 1;
    }

    for(i=0;i<n;i++)
    {
        A[i]=(int*)malloc(m * sizeof(int)); //matricea A are n linii si m coloane, deci fiecare linie A[i] trebuie sa aiba m elemente

        if(A[i]==NULL)
        {
            for(j=0;j<i;j++)
                free (A[j]);
            free (A);
            free (B);
            return 1;
        }
    }

    for(i=0;i<m;i++)
    {
        B[i]=(int*)malloc(n * sizeof(int)); //matricea B are m linii si n coloane, deci fiecare linie B[i] trebuie sa aiba n elemente

        if(B[i]==NULL)
        {
            for(j=0;j<n;j++)
                free (A[j]);
            free (A);

            for(j=0;j<i;j++)
                free (B[j]);
            free (B);
            return 1;
        }
    }

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&A[i][j]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            B[j][i]=A[i][j];

    printf("Transpusa matricei A este: ");

    for(i=0;i<m;i++) //matricea B are m linii si n coloane
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d ",B[i][j]);
    }

    for(i=0;i<n;i++)
        free (A[i]);

    for(j=0;j<m;j++)
        free (B[j]);

    free (A);
    free (B);

    return 0;
}
