/*
 * main.c
 *
 * Author: Gramegna Simone
 *
 */

#include <stdio.h>
#include <stdlib.h>

// funzione per elevare a potenza un numero con esponente dato
int potenza( int num, int exp );

// funzione per la somma dei numeri elevati a potenza
int SommaPotenza( int numero, int exp_max );


int main()
{

    int n, k;
	int sommatoria;

	printf("Inserisci il numero da elevare a  potenza \n");
		scanf("%d" ,&k);

	printf("Inserisci l'esponente massimo \n");
	    scanf("%d" ,&n);

	if( n > 0 && k > 0 )
	{
	    sommatoria = SommaPotenza( k,n );

	    printf("La sommatoria delle potenze di %d fino a %d e' uguale a %d \n" ,k,n, sommatoria);

	}
	else
	{
		printf("Valori non validi \n");
	}


return 0;
}

int potenza( int num, int exp )
{
    int i = 0;
    int pow = 1;

        while( i < exp )
        {

            pow = pow * num;

            i = i + 1;
        }

    return pow;
}

int SommaPotenza( int numero, int exp_max )
{
    int sommatoria = 0;
    int pow;
    int i = 1;

        while( i <= exp_max )
        {
            pow = potenza( numero, i);
            sommatoria = sommatoria + pow;

            i = i + 1;
        }

    return sommatoria;
}
