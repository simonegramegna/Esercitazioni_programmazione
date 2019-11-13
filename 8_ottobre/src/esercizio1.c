/**
 * 
 * Esercitazione 8 ottobre 2019
 * 
 * author: Gramegna Simone
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// funzione per calcolare multiplo
int multipli( int index, int num );

// funzione per stampa multipli
void stampamultipli( int num, int max );


int main()
{
    int n;
    int k;

    printf("Inserisci il numero di cui vuoi trovare i multipli \n");
        scanf("%d" ,&n);

    printf("Inserisci il numero massimo di multipli da trovare \n");
        scanf("%d" ,&k);

    if( k > 0 )
    {

        printf("I %d multipli di %d sono: " ,k ,n);
        stampamultipli(n,k);

    }
    else
    {
        printf("Valore massimo non valido! \n");
    }

        system("pause");
    return 0;
}

int multipli( int index, int num )
{
    return index * num;
}

void stampamultipli( int num, int max )
{

    int i = 1;

    while( i <= max )
    {
        
        int res = multipli(i, num);

            printf(" %d " ,res);

        i = i + 1; 

    }
}
