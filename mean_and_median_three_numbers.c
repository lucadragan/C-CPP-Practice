// Function that calculates the arithmetic mean and median of three strictly positive natural numbers (a, b, c)
//Mediana reprezintă valoarea de mijloc din cadrul unui șir de numere. Pentru a o afla, ordonați mai întai șirul crescător. Apoi, dacă numărul de termeni este impar, mediana va fi egală cu elementul din poziția din mijloc, altfel, cu media aritmetică a celor două numere din mijloc
#include <stdio.h>

void calcul(int n,int v[3],float *media, float *mediana) //scriem mereu v[3] daca vrem maxim trei elemente in vector
 {
    int suma=0;
    suma=v[0]+v[1]+v[2];
    *media= (float)suma/3; //calculam media numerelor din vector

    int i,j,aux,sum=0;
    {
    for(i=0;i<3-1;i++)
        for(j=i+1;j<3;j++)
        {
            if(v[i]>v[j]) //sortam vectorul crescator, acest pas ne ajuta in determinarea medianei unui set de numere
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }

    if(n%2==1)
        *mediana=v[(n-1)/2]; //avand mereu exact trei numere in sir, putem spune ca mediana va fi egala cu v[1]
          else if(n%2==0) //aceasta conditie nu mai este necesara, problma impunand un set de numere de forma a,b,c
          {
            sum=v[(n/2)-1]+v[n/2];
            *mediana=(float)sum/2;
          }
}

int main()
{
    int n,i,v[3];
    float medie,mediana;
    scanf("%d",&n);
    if(n!=3)
        return 1; //putem bloca direct n=3, fara sa il mai citim si sa putem conditii, in indeplinirea cerintei problemei
    for(i=0;i<3;i++)
    {
        scanf("%d",&v[i]);
        while(v[i]<=0)
            {
            printf("Introduceti un numar mai mare decat 0: "); //programul nu va trece peste niciun numar negativ, fiind obligati sa rescriem unul strict pozitiv
            scanf("%d",&v[i]);
            }
    }

    calcul(n,v,&medie,&mediana); //aplelam functia in consecinta, si luam valorile pe care le urmarim din adresa pointerilor

    printf("Media celor trei numere din sir este egala cu: %0.2f\n",medie);
    printf("Mediana setului de numere este egala cu: %0.2f",mediana);

    return 0;
}
