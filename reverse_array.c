// Function that reverses an array by swapping opposite elements
#include <stdio.h>

void inversare(int v[],int n)
{
    int i,aux;
    for(i=0;i<n/2;i++)
    {
        aux=v[i];
        v[i]=v[n-i-1];
        v[n-i-1]=aux;
    }
}
int main()
{
    int i,n,v[100];
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    inversare(v,n);
    for(i=0;i<n;i++)
    {
        printf("%d ", v[i]);
    }
    return 0;
}
