#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void unos_matrice(int **matrica, int x, int y)
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
int stepen_dvojke(int **matrica, int x, int y)
{
    int i, j, stop;
    stop = 0;
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            if ((matrica[i][j] & (matrica[i][j] - 1)) == 0)
            {
                continue;
            }
            else
            {
                stop = matrica[i][j];
                break;
            }
        }
        if (stop != 0)
        {
            break;
        }
    }
    if (i == y && j == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void ispis_matrice(int **matrica, int x, int y)
{
    int i, j;
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
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
void nova_matrica(int **matrica, int x, int y, char *smer)
{
    int k;
    int i, j;
    if (strcmp(smer, "left") == 0)
    {
        for (i = 0; i < y; i++)
        {
            k = 0; // slobodno polje
            for (j = 0; j < x; j++)
            {
                if (matrica[i][j] > 0)
                {
                    matrica[i][k] = matrica[i][j];
                    if (k != j)
                    {
                        matrica[i][j] = 0;
                    }
                    if (matrica[i][k] == matrica[i][k - 1] && k > 0)
                    {
                        matrica[i][k - 1] = matrica[i][k - 1] * 2;
                        matrica[i][k] = 0;
                    }
                    k++;
                }
            }
        }
    }
    if (strcmp(smer, "right") == 0)
    {
        for (i = 0; i < y; i++)
        {
            k = x;
            for (j = x; j > 0; j--)
            {
                if (matrica[i][j] > 0)
                {
                    matrica[i][k] = matrica[i][j];
                    if (k != j)
                    {
                        matrica[i][j] = 0;
                    }
                    if (matrica[i][k] == matrica[i][k + 1] && k < x)
                    {
                        matrica[i][k + 1] = matrica[i][k + 1] * 2;
                        matrica[i][k] = 0;
                    }
                    k--;
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
        int **matrica = (int **)malloc(visina * sizeof(int *));
        for (i = 0; i < visina; i++)
        {
            matrica[i] = (int *)malloc(sirina * sizeof(int));
        }
        unos_matrice(matrica, sirina, visina);
        if (stepen_dvojke(matrica, sirina, visina))
        {
            smer = malloc(6);
            scanf("%s", smer);
            ispis_matrice(matrica, sirina, visina);
            printf("\n");
            nova_matrica(matrica, sirina, visina, smer);
            ispis_matrice(matrica, sirina, visina);
        }
    }
    return 0;
}
