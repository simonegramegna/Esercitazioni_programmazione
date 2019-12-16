/*
 * main.c
 *
 * Created on: 12 dic 2019
 *
 * Author: Gramegna Simone
 *
 */

#include <stdio.h>
#include <stdlib.h>

// definisco la dimensione del vettore
#define N 10

// funzione ricorsiva per la somma ricorsiva
int SommaVet( int vet[] ,int dim );

int main()
{

	// creo vettore di vettore di N elementi
	int numeri[N] = {10,20,30,40,50,60,70,80,90,100};

		// calcolo la somma degli elementi nel vettore
		int somma = SommaVet(numeri,N);

		printf("La somma degli elementi el vettore dato e' %d \n" ,somma);

	system("pause");
return 0;
}

int SommaVet( int vet[] ,int dim )
{
	
	int somma;

	if(dim == 1)
	{
		somma = vet[0];
	}
	else
	{
		somma = vet[dim-1] + SommaVet(vet,dim-1);
	}
	return somma;
}

