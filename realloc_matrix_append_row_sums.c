// Dynamically allocate an n x m matrix, extend each row using realloc to store its elements' sum in the new last column, and print the result.

//Cititi o matrice cu n linii si m coloane, alocata dinamic. Extindeti fiecare linie folosind realloc, astfel încat matricea sa aiba m + 1 coloane. In ultima coloana memorati suma elementelor initiale ale fiecarei linii. Afisati matricea rezultata.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,suma=0;
    int**M,*p;
    scanf("%d%d",&n,&m);

    M=(int**)malloc(n * sizeof(int*)); //alocam vectorul de pointeri (n linii)

    if(M==NULL) //verificam daca sistemul a avut memorie
        return 1; //iesim din program cu cod de eroare


    for(i=0;i<n;i++)
    {
        M[i]=(int*)malloc(m * sizeof(int)); //Alocam fiecare linie în parte (fiecare cu m coloane)

        if(M[i]==NULL)      //eliberam DOAR liniile care au reușit sa se aloce pana la pasul 'i' (de la 0 la i-1)
           {                //deoarece linia 'i' a eșuat (e NULL), iar liniile de după 'i' nici nu au fost create inca
            for(j=0;j<i;j++)
                free (M[j]);
            free (M); //la final eliberam si vectorul principal de pointeri
            return 1;
           }
    }

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
    {
        scanf("%d",&M[i][j]); //citim elementele initiale ale matricei
    }

    for(i=0;i<n;i++) //calculam suma fiecarei linii si extindem linia cu o coloana
    {
        suma=0; //resetam suma la 0 pentru fiecare linie noua
        for(j=0;j<m;j++)
            suma=suma+M[i][j];

        //incercam sa marim linia M[i] de la 'm' la 'm + 1' elemente
        //salvam rezultatul intr-un pointer auxiliar 'p', NU direct în M[i]
        //motivul: dacă realloc esueaza, returneaza NULL. Daca am pune direct în M[i], am pierde adresa veche a liniei si nu am mai putea face free()

        p=(int*)realloc(M[i],(m+1) * sizeof(int));

        if(p==NULL) //daca redimensionarea a esuat, toate cele 'n' linii initiale există incă in memorie, deci le eliberam pe toate
        {
            for(j=0;j<n;j++)
                free (M[j]);

            free (M);
            return 1;
        }

        M[i]=p; //acum ca suntem siguri ca realloc a reușit (p!=NULL), actualizam linia M[i] cu noua adresa
        M[i][m]=suma; //punem suma pe ultima pozitie nou creata (indicii merg acum de la 0 la m, deci 'm' este chiar coloana m + 1)
    }

    printf("Matricea rezultata este:\n"); //afisam matricea extinsa

    for(i=0;i<n;i++)
    {
        for(j=0;j<m+1;j++) //mergem pana la 'm + 1' ca sa includem si noua coloana cu sume
        {
            printf("%d ",M[i][j]);
        }
        printf("\n"); //trecem pe randul urmator dupa terminarea unei linii
    }

    for(i=0;i<n;i++) //eliberam toata memoria la final (intai fiecare linie, apoi vectorul de linii)
        free (M[i]);

    free (M);

    return 0;
}
