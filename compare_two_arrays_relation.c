// Compares two arrays of equal length and determines if they are identical, reversed, or completely different
#include <stdio.h>

int main()
{
    int n,i,v[100],u[100];
    int identici=1;
    int inversati=1;

    scanf("%d",&n); //2 vectori cu acelasi numar de elemente, folosim acelasi n si acelasi i pentru ambii, citim o singura data

    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }

    for(i=0;i<n;i++)
    {
        scanf("%d",&u[i]); //totusi citirea elementelor se face pentru fiecare in parte
    }

    for(i=0;i<n;i++)
    {
        if(v[i]!=u[i])
           {
               identici=0; //identici e folosit pe post de stegulet
               break; //oprire rapida, te scoate din for la prima greseala, eficientizare
           }
    }

    for(i=0;i<n;i++)
    {
        if(v[i]!=u[(n-1)-i])
             {
                 inversati=0; //inversati e folosit pe post de stegulet
                  break; //oprire rapida, te scoate din for la prima greseala, eficientizare
             }
    }

    if(identici==1)
    {
        printf("Vectorii sunt identici.");
    }
    else if (inversati==1)
    {
        printf("Vectorii sunt inversati.");
    }
    else {printf("Vectorii sunt diferiti.");}

    return 0;
}
