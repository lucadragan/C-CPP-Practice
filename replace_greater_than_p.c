// Replaces array elements strictly greater than a natural value p with p and counts the replacements
#include <stdio.h>

int main()
{
    int i,n,v[100],p,k=0;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }

    scanf("%d",&p);

    for(i=0;i<n;i++)
    {
        if(v[i]>p)
           {
           v[i]=p;
           k++;
           }
    }

    for(i=0;i<n;i++)
    {
      printf("%d ",v[i]);
    }

    printf("\nAu fost efectuate %d inlocuiri ",k);

    return 0;
}
