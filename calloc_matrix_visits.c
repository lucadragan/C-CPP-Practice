// Dynamically allocate a zero-initialized n x m grid using calloc, record k visits by incrementing cell coordinates, and print the final grid

//Cititi dimensiunile n si m ale unei matrici (grile). Folositi functia calloc, astfel încat toate elementele matricei să fie initial zero. Cititi un număr k de ‘vizite’, urmat de k perechi de indici valizi (i, j). Pentru fiecare vizita într-un element al grilei, incrementati valoarea de la pozitia respectiva. Afisati matricea finala, in care fiecare element indica de cate ori a fost vizitata celula respectiva.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,k,pas;
    int **M;
    scanf("%d%d",&n,&m);

    M=(int**)calloc(n, sizeof(int*));

    for(i=0;i<n;i++)
    {
        M[i]=(int*)calloc(m, sizeof(int)); //alocarea matricei cu calloc (toata matricea devine 0)
    }

    scanf("%d",&k); //citirea numarului de vizite si procesarea lor pe rand

    for(pas=0;pas<k;pas++)
    {
        scanf("%d%d",&i,&j);
        M[i][j]++; //incrementarea elementului din matrice (cresterea lui cu 1)
    }

    printf("\n");

    for(i=0;i<n;i++) //afisarea matricei finale
    {
        for(j=0;j<m;j++)
            printf("%d ",M[i][j]);
            printf("\n"); //trecem pe randul urmator dupa fiecare linie
    }

    for(i=0;i<n;i++) //eliberarea memoriei
    {
        free (M[i]);
    }

    free (M);

    return 0;
}
