/*
 * esercizio2.c
 *
 * Author: Gramegna Simone
 *
 */

#include <stdio.h>
#include <stdlib.h>

int divisibile(int dividendo, int divisore);

int main()
{
    int n,k;
    int div;

    setbuf(stdout, NULL);

    printf("Inserisci il dividendo \n");
        scanf("%d" ,&n);

    printf("Inserisci il divisore \n");
        scanf("%d" ,&k);

        div = divisibile(n, k);

        if( div == 1 )
        {
            printf("n e' divisibile per k \n");
        }
        else
        {

            printf("n non e' divisibile per k \n");
        }

        system("pause");
return 0;
}

int divisibile(int dividendo, int divisore)
{
    int divisibile = 0;
    int resto;

    resto = dividendo % divisore;

    if( resto == 0 )
    {
        divisibile = 1;
    }

    return divisibile;
}
