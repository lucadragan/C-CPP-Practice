// Finds and counts elements that appear exactly once in an array using nested loops
#include <stdio.h>

int main()
{
    int i,j,n,v[100],aparitie;
    int k=0;

    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }

    for(i=0;i<n;i++)
    {
    aparitie=0;

      for(j=0;j<n;j++) //contorizarea o va lua mereu de la inceputul vectorului, in timp ce primul for face ca vectorul sa fie parcurs
      {
          if(v[i]==v[j])
            aparitie++;
      }
      if(aparitie==1) //daca va fi 2 e clar ca va aparea de 2 ori
      {
          printf("%d ", v[i]);
          k++;
      }
    }

    if(k==0)
    {
        printf("Nu exista elemente care apar o singura data.");
    } else
    {
       printf("\nNumarul lor este: %d ",k);
    }

    return 0;
}
