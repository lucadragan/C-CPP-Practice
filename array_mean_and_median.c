// Two functions that return the arithmetic mean and the median of an arbitrary set of strictly positive natural numbers
//Mediana reprezintă valoarea de mijloc din cadrul unui șir de numere. Pentru a o afla, ordonați mai întai șirul crescător. Apoi, dacă numărul de termeni este impar, mediana va fi egală cu elementul din poziția din mijloc, altfel, cu media aritmetică a celor două numere din mijloc
#include <stdio.h>

 float medie(int n,int v[100])
 {
    int suma=0,i;
    float medie1;
    for(i=0;i<n;i++)
    {
        suma=suma+v[i];
    }
    medie1= (float)suma/n;
    return medie1;
 }

 float mediana(int n,int v[100])
 {
    int i,j,aux,sum=0;
    float med,mediana1;
    for(i=0;i<n-1;i++) //sortam vectorul crescator
    {
        for(j=i+1;j<n;j++)
        {
            if(v[i]>v[j])
            {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            }
        }
    }

    if(n%2==1)
        mediana1=v[(n-1)/2];
          else if(n%2==0)
          {
              sum=v[n/2]+v[(n/2)-1];
              med= (float)sum/2;
              mediana1=med;
          }

  return mediana1;
 }
int main()
{
    int n,i,v[100];
    float x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        while(v[i]<=0)
        {
         printf("Numerele introduse trebuie sa fie naturale, strict mai mare ca 0 ");
         scanf("%d",&v[i]);
        }
    }
    x=medie(n,v);
    y=mediana(n,v);
    printf("Media numerelor este egala cu: %0.2f\n",x);
    printf("Mediana setului de numere esta egala cu: %0.2f",y);

    return 0;
}
