// Function that extracts all even elements from an array into a new array
#include <stdio.h>

int elempare(int v[],int n,int p[])
{
    int i,k=0;
    for(i=0;i<n;i++)
    {
        if(v[i]%2==0)
           {
               p[k]=v[i];
               k++;
           }
    }
    return k;
}

int main()
{
    int i,n,v[100],p[100],x;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }

    x=elempare(v,n,p);
    if(x!=0)
    {
    for(i=0;i<x;i++)
        {
        printf("%d ", p[i]);
        }
    }
       else if(x==0)
               printf("Nu exista elemente pare in vector ");

    return 0;
}
