// Reads a matrix and prints it rotated 90 degrees clockwise
#include <stdio.h>

int main()
{
    int n,m,i,j,A[100][100],x,y,B[100][100];

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&A[i][j]);
    }

    x=0;
    y=0;

    for(j=0;j<m;j++)
    {
        y=0;
        for(i=n-1;i>=0;i--)
        {
            B[x][y]=A[i][j];
            y++;
        }
        x++;
    }

    for(x=0;x<m;x++)
    {
        for(y=0;y<n;y++)
        {
            printf("%d ", B[x][y]);
        }
        printf("\n");
    }


    return 0;
}
