/*
 * main.c
 *
 *  Author: Gramegna Simone
 * 
 * 	Esercitazione 31 ottobre
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define RIGHE 4
#define COLONNE 3
#define COND 3
#define MAX 10

// matrice data 4 righe, 3 colonne
int matrix[RIGHE][COLONNE] = {{1,6,4},{2,4,5},{3,1,6},{4,0,7}};

// funzione per cercare le colonne che soddisfano la condizione richiesta
int CercaColonna( int r, int c);

// funzione per controllare la prsenza di elementi maggiori di 10 
int Controllo( int r, int c);

// funzione per stampare la singola colonna
void StampaColonna( int r, int c );

// funzione per stampare i risultati ottenuti
void StampaRisultati( int r, int c);

int main()
{

		StampaRisultati(RIGHE,COLONNE);

		system("pause");

	return 0;
}

int CercaColonna( int r, int c )
{

	int x = 1;

	int counter = 1;
	int condition = 0;

	while( (x < r) && (counter != COND) )
	{
		if( matrix[x][c] == matrix[x-1][c] + 1 )
		{
			counter = counter + 1;
		}
		x = x + 1;
	}

	if( counter == COND )
	{
		condition = 1;

	}
	return condition;
}

void StampaColonna( int r, int c )
{

	int x = 0;

	while( x < RIGHE )
	{

		printf("%d \n" ,matrix[x][c]);
		x = x + 1;
	}

}

void StampaRisultati( int r, int c)
{
	int x = 0;

	while( x < c )
	{
		int check;

		check = CercaColonna( RIGHE, x );

		if( check == 1 )
		{
			StampaColonna( RIGHE, x );
			printf("\n");
		}


		x = x + 1;
	}
}

int Controllo( int r, int c)
{
	int i = 0;
	int control = 0;
	int j;

	while( i < c && control != 1 )
	{
		j = 0;
		while( j < r && control != 1)
		{
			if( matrix[j][i] >= MAX )
			{
				control = 1;
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return control;
}



