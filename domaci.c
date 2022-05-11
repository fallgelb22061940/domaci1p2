#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void unos_matrice(int **matrica, int x, int y) // unos u generisanu matricu
{
    int i, j;
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            scanf("%d", &matrica[i][j]);
        }
    }
}
int stepen_dvojke(int **matrica, int x, int y) // provera da li je svaki član matrice stepen dvojke
{
    int i, j, stop;
    stop = 0;
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            if ((matrica[i][j] & (matrica[i][j] - 1)) == 0) // ako je matrica[i][j] binarno i matrica[i][j]-1 jednako 0 tad jedino je broj stepen dvojke jer inače bi rezultat bio 1xxxxxx...
            {
                continue;
            }
            else
            {
                stop = matrica[i][j];
                break;
            }
        }
        if (stop != 0) // da se zaustavi petlja
        {
            break;
        }
    }
    if (i == y && j == x)
    {
        return 1; // ako se ne zaustavi petlja dok ne dođe do kraja, vrati true
    }
    else
    {
        return 0; // vrati false
    }
}
void ispis_matrice(int **matrica, int x, int y)
{
    int i, j;
    for (i = 0; i < y; i++) // pristup matrici po y osi
    {
        for (j = 0; j < x; j++) // pristup matrici po x osi
        {
            printf("%d", matrica[i][j]);
            if (j != x - 1)
            {
                printf(" ");
            }
        }
        if (i != y - 1)
        {
            printf("\n");
        }
    }
}
void nova_matrica(int **nova, int x, int y, char *smer, int **stara)
{
    int i, j;
    if (strcmp(smer, "left") == 0) //šift levo
    {
        for (i = 0; i < y; i++)
        {
            int brojac = 0;
            for (j = 0; j < x; j++)
            {
                if (stara[i][j] != 0)
                {
                    nova[i][brojac] = stara[i][j];                             // preslikavanje u novu matricu tako da nule idu na kraj
                    if (brojac != 0 && nova[i][brojac] == nova[i][brojac - 1]) // brojač veći od 0 i ako se poklapaju trenutni i prethodni element spoji
                    {
                        nova[i][brojac - 1] = nova[i][brojac - 1] * 2;
                        nova[i][brojac] = 0;
                    }
                    brojac++;
                }
            }
            brojac = 0;
            for (j = 0; j < x; j++)
            {
                if (nova[i][j] != 0) //šiftovanje ostatka u levo
                {
                    nova[i][brojac] = nova[i][j];
                    if (j > brojac)
                    {
                        nova[i][j] = 0;
                    }
                    brojac++;
                }
            }
        }
    }
    if (strcmp(smer, "right") == 0) //šift desno, urađen simetrično u odnosu na šift levo
    {
        for (i = 0; i < y; i++)
        {
            int brojac = x - 1;
            for (j = x - 1; j >= 0; j--)
            {
                if (stara[i][j] != 0)
                {
                    nova[i][brojac] = stara[i][j];
                    if (brojac != x - 1 && nova[i][brojac] == nova[i][brojac + 1])
                    {
                        nova[i][brojac + 1] = nova[i][brojac + 1] * 2;
                        nova[i][brojac] = 0;
                    }
                    brojac--;
                }
            }
            brojac = x - 1;
            for (j = x - 1; j >= 0; j--)
            {
                if (nova[i][j] != 0)
                {
                    nova[i][brojac] = nova[i][j];
                    if (j < brojac)
                    {
                        nova[i][j] = 0;
                    }
                    brojac--;
                }
            }
        }
    }
}
int main()
{
    int i, j, sirina, visina;
    char *smer;
    scanf("%d%d", &visina, &sirina);
    if (visina > 0 && sirina > 0)
    {
        int **matrica = (int **)malloc(visina * sizeof(int *)); // formiranje matrice
        for (i = 0; i < visina; i++)
        {
            matrica[i] = (int *)malloc(sirina * sizeof(int));
        }
        unos_matrice(matrica, sirina, visina);
        if (stepen_dvojke(matrica, sirina, visina))
        {
            smer = malloc(6);
            scanf("%s", smer);
            int **matrica1 = (int **)malloc(visina * sizeof(int *)); // formiranje nove matrice
            for (i = 0; i < visina; i++)
            {
                matrica1[i] = (int *)malloc(sirina * sizeof(int));
            }
            ispis_matrice(matrica, sirina, visina); // pozivi funkcija
            printf("\n");
            nova_matrica(matrica1, sirina, visina, smer, matrica);
            ispis_matrice(matrica1, sirina, visina);
            for (i = 0; i < visina; i++) // dealokacija memorije nove matrice
            {
                free(matrica1[i]);
            }
            free(matrica1);
            free(smer);
        }
        for (i = 0; i < visina; i++) // dealokacija memorije stare matrice
        {
            free(matrica[i]);
        }
        free(matrica);
    }
    return 0;
}
