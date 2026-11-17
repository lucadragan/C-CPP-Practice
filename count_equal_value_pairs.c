// Counts the number of pairs of elements at different indices (i < j) in an array that have equal values
#include <stdio.h>

int main()
{
    int n,i,j,v[100];
    int k=0;

    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }

    for(i=0;i<n;i++)
    {
       for(j=i+1;j<n;j++)
       {
           if(v[i]==v[j])
              k++;
       }

    }

    printf("%d ", k);

    return 0;
}
