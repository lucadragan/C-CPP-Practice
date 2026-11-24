// Dynamically resize an array v via a function using realloc to append a value x at the end, preserving the original array on failure.

//Cititi in main un vector v, alocat dinamic, cu n elemente intregi, apoi o valoare intreaga x. Scrieti o functie care primeste adresa pointerului v, dimensiunea curenta si valoarea x. Functia redimensioneaza vectorul folosind realloc si adauga x la final. Daca redimensionarea esueaza, pointerul si elementele vectorului initial trebuie sa ramana nemodificate. In main, incrementati n numai daca functia returneaza 1, apoi afisati vectorul si eliberati memoria.
#include <stdio.h>
#include <stdlib.h>

int adauga(int **v,int n,int x) //functia este de tip 'int' (nu void) pentru a putea semnala succesul (return 1) sau esecul (return 0)
                                //primim ADRESA pointerului v (int **v) ca sa putem modifica pointerul original din main daca realloc il muta in memorie
{
    int *p; //folosim pointerul auxiliar 'p' ca masura de siguranta!
    //daca realloc esueaza, returneaza NULL. Daca am salva direct in *v, am pierde adresa vectorului vechi si n-am mai putea nici sa-l afisam intact, nici sa-i facem free()

    p=(int *)realloc(*v,(n+1)*sizeof(int));

    if(p==NULL)
        return 0; //daca redimensionarea a esuat, NU facem free(*v), deoarece cerinta spune ca vectorul initial sa ramana intact

    *v=p; //acum ca suntem siguri ca realloc a reusit, actualizam pointerul din main cu noua adresa
    (*v)[n]=x; //punem elementul x pe ultima pozitie nou creata (indexul 'n', deoarece indicii vechi erau de la 0 la n-1)
               //parantezele (*v)[n] sunt obligatorii deoarece '[]' are prioritate mai mare decât '*'

    return 1; //semnalam catre main ca operatia a reusit
}

int main()
{
    int i,n,x;
    int *v;
    scanf("%d",&n);

    v=(int*)malloc(n * sizeof(int)); //alocam memorie initiala pentru cele n elemente

    if(v==NULL)
        return 1;

    for(i=0;i<n;i++)
        scanf("%d",&v[i]);

    scanf("%d",&x);

    if(adauga(&v,n,x)==1) //trimitem '&v' (adresa pointerului v) si verificam daca functia a returnat 1 (succes)
    {
          n++; //incrementam n DOAR aici, pentru ca acum vectorul are intr-adevar n + 1 elemente

          printf("Vectorul rezultat este: ");

          for(i=0;i<n;i++) //mergem pana la noul 'n' (care include deja si elementul x de la final)
              printf("%d ",v[i]);
    }

         else
        {   //daca realloc a esuat (a returnat 0), 'n' nu se incrementeaza, iar 'v' a ramas nemodificat
            printf("Redimensionarea vectorului nu a reusit ");
            printf("\nVectorul ramane: ");

            for(i=0;i<n;i++)
              printf("%d ",v[i]);
        }

    free(v); //indiferent daca realloc a reusit sau nu, eliberam memoria vectorului la final

    return 0;
}
