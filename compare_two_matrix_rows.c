// Compares two user-selected rows (1-indexed) of an n x m matrix to check if they are identical, reversed, or different
#include <stdio.h>

int main()
{
    int n,m,i,j,M[100][100],L1,L2; //L1 si L2 reprezinta liniile pe care vrem sa le comparam
    int identice=1;
    int inversate=1;

    scanf("%d%d", &n,&m); //citim liniile si coloanele matricei

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d", &M[i][j]); //citim elementele matricei
        }
    }

    scanf("%d%d", &L1,&L2);
    L1--; //Ajuta sa numerotam corect liniile in functie de indici, linia 3 va fi in C linia 2,L1-- insemnand L1=L1-1, astfel se va afisa linia corespunzatoare
    L2--;

    for(j=0;j<m;j++)
    {
        if(M[L1][j]!=M[L2][j])
        {
            identice=0; //identice e folosit pe post de stegulet
            break; //oprire rapida, te scoate din for la prima neconcordanta, eficientizare
        }
    }

    for(j=0;j<m;j++)
    {
            if(M[L1][j]!=M[L2][(m-1)-j])
            {
            inversate=0;//inversate e folosit pe post de stegulet
            break;//oprire rapida, te scoate din for la prima neconcordanta, eficientizare
            }
    }

    if(identice==1)
    {
        printf("Liniile matricei sunt identice.");
    }
    else if(inversate==1)
    {
        printf("Liniile matricei sunt inversate.");
    }
    else
    {
        printf("Liniile matricei sunt diferite.");
    }

    return 0;
}
