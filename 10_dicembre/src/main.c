/*
 * main.c
 *
 *  Created on: 10 dic 2019
 *      Author: simone
 */


#include <stdio.h>
#include <stdlib.h>

// funzione per leggere numero caratteri del file
int NumCaratteri( FILE* fp );

// funzione per allocare vettore di caratteri
void AllocVet( char* vetcaratteri, int dim );

// funzione per calcolare la dimensione dei caratteri da stampare
int DimVetStampa( int dim_init, int freq );

// funzione che stampa il numero di caratteri trovati
void StampaContaCarattere( int res );

// funzione di stampa della sequenza
void StampaSequenza( char* seq, int dim );

// funzione che dealloca il vettore
void freevet( char* ch );


int main()
{
	FILE* fp;
	char* vetc;
	int num3 = 3;

	fp = fopen("file.txt","r");

	if( fp == NULL )
	{

		printf("Errore: file non aperto \n");

	}

	int dimf = NumCaratteri(fp);

	int dimall = DimVetStampa(dimf , num3);

	AllocVet(vetc, dimall);

	// riposiziono la testina di lettura del file all'inizio del file
	rewind(fp);

	char* s = UnoN(&vetc,dimall,num3,fp);

	int x = 0;

	while( x < dimall )
	{
		printf("%c \n" ,*(s+x));
		x++;
	}


	//int x = ContaCarattere(vetc, dimall, 'f' );

	//StampaContaCarattere(x);


	freevet(vetc);

	fclose(fp);

	system("pause");
return 0;
}

int NumCaratteri( FILE* fp )
{

	int numcaratteri = 0;

	char c1 = fgetc(fp);

	while( c1 != EOF )
	{
		c1 = fgetc(fp);
		numcaratteri = numcaratteri + 1;
	}
	return numcaratteri;
}

void AllocVet( char* vetcaratteri, int dim )
{
	vetcaratteri = (char*) calloc(dim,sizeof(char));
}

int DimVetStampa( int dim_init, int freq )
{
	int dimvet = (int) dim_init / freq;

	return dimvet;
}

void StampaContaCarattere( int res )
{
	printf("Il carattere e' presente %d volte" ,res);
}

void StampaSequenza( char* seq, int dim )
{
	int i = 0;

	while( i < dim )
	{
		printf(" %c " ,*(seq + i));
		i = i + 1;
	}
}

void freevet( char* ch )
{
	free(ch);
}
