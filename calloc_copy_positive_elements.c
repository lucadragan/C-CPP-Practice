// Dynamically allocate an array v, use a function with calloc to copy only its strictly positive elements into a second array u at their original positions, and print both.

//Cititi in main un vector v, alocat dinamic, cu n elemente intregi si declarati un pointer u, initializat cu NULL. Scrieti o functie care primeste vectorul v, dimensiunea sa si adresa pointerului u. Functia aloca memorie pentru u folosind calloc si copiaza pe pozitiile corespunzatoare numai elementele strict pozitive din v. Celelalte pozitii raman zero. Vectorul v trebuie sa ramana nemodificat. Afisati ambii vectori si eliberati memoria în main.
#include <stdio.h>
#include <stdlib.h>

void alocare(int *v,int n,int **u)     //primim vectorul v (int *v), dimensiunea n și ADRESA pointerului u (int **u)
                                       //folosim pointer dublu (**) pentru ca alocarea facuta aici sa modifice direct pointerul 'u' din main
{
    int i;

    *u=(int*)calloc(n,sizeof(int));  //dereferentiem (*u) ca sa modificam pointerul original din main
                                     //folosim calloc pentru ca toate cele n elemente să fie initializate automat cu 0 (alocare)

    if(*u==NULL)
        return;  //functia este 'void' (nu returneaza valori), deci la eroare iesim cu simplu 'return;' (fara 0 sau 1)

    for(i=0;i<n;i++)
    {
        if(v[i]>0)
            (*u)[i]=v[i]; //PARANTEZELE (*u)[i] SUNT OBLIGATORII:
                          //operatorul '[]' are prioritate mai mare decât '*'. fara paranteze (*u[i]), compilatorul ar incerca intai sa indexeze si abia apoi sa dereferentieze (eroare!)
    }
    //nu punem 'return 0;' la final pentru ca functia este de tip 'void'
}

int main()
{
    int i,n;
    int *v,*u=NULL;
    scanf("%d",&n);

    v=(int*)malloc(n * sizeof(int));

    if(v==NULL)
        return 1; //daca alocarea a esuat, 'v' este deja NULL (nu necesita free), doar oprim programul

    for(i=0;i<n;i++)
        scanf("%d",&v[i]);

    alocare(v,n,&u); //trimitem '&u' (adresa pointerului u) pentru ca functia sa il poata aloca si modifica

    if(u==NULL) //verificam daca alocarea din interiorul functiei a reusit, daca 'u' a ramas NULL, eliberam 'v' (care era deja alocat!) inainte sa ieșim cu eroare
    {
        free(v);
        return 1;
    }

    printf("Vectorul v este: ");

    for(i=0;i<n;i++)
        printf("%d ",v[i]);

    printf("\n");

    printf("Vectorul u este: ");

    for(i=0;i<n;i++)
        printf("%d ",u[i]);

    free(v); //eliberam memoria ambilor vectori la finalul programului (un singur free pentru fiecare vector)
    free(u);

    return 0;
}
