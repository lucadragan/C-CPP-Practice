// Void function that swaps the values of two integers using pointers
#include <stdio.h>

 void interschimbare(int *m,int *p)
 {
     int aux;
     aux=*m;
     *m=*p;
     *p=aux;
 }

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    interschimbare(&a,&b);
    printf("Cele doua numere interschimbate vor fi: %d %d",a,b);
    return 0;
}
