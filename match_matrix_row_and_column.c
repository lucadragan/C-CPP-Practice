// Checks if a square matrix contains a row and a column with identical elements (first in the exact same order, then regardless of order)
#include <stdio.h>

int main()
{
    int i,j,m,n,M[100][100],k,p,l,adev,v[100],w[100],aux;
    scanf("%d%d",&n,&m);

    if(n!=m) //o linie si o coloana nu pot contine aceleasi elemente decat daca matricea este patratica
        return 0;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
    {
        scanf("%d", &M[i][j]);
    }
    // vedem daca in matrice exista o linie care contine aceleasi elemente cu o coloana, in aceeasi ordine macar, prima data
    for(i=0;i<n;i++) //i alege linia
    {   for(j=0;j<m;j++) //j alege coloana
        {
            adev=0;
            for(k=0;k<n;k++) //k compara elementele din linia și coloana alese
                {
            if(M[i][k]==M[k][j])
               adev++;}
        if(adev==n)
            {for(p=0;p<n;p++) // p parcurge linia pentru afisare
                  {printf("%d ", M[i][p]);
                  printf("\n");}
                }
        }
    }

    //vedem daca in matrice exista o linie care contine aceleasi elemente cu o coloana, indiferent de ordinea acestora
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            for(k=0;k<n;k++)
               {
               v[k]=M[i][k]; //cpoiem linia si coloana sub forma de vectori
               w[k]=M[k][j];
               }
               for(k=0;k<n-1;k++)
                   for(l=k+1;l<n;l++)
                {
                    if(v[k]>v[l]) //sortam vectorul v
                    {
                    aux=v[k];
                    v[k]=v[l];
                    v[l]=aux;
                    }
                }
               for(k=0;k<n-1;k++)
                   for(l=k+1;l<n;l++)
               {
                   if(w[k]>w[l]) //sortam vectorul w
                   {
                       aux=w[k];
                       w[k]=w[l];
                       w[l]=aux;
                   }
               }
        adev=0;
        for(k=0;k<n;k++)
        {
            if(v[k]==w[k]) //comparam vectorii
                adev++;
        }
        if(adev==n) //daca sunt identici afisam linia
        {
            for(k=0;k<n;k++)
                printf("%d ", M[i][k]);
                printf("\n");
        }
        }
    }

    return 0;
}
