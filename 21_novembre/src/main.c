/*
 * main.c
 *
 *  Created on: 21 nov 2019
 *
 *  Author: Gramegna Simone
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define DIMVET 10 

// funzione per allocare il vettore di stringhe
void AllocaVetString( char** vetstring, int dim );

// funzione per calcolare la lunghezza della stringa
int LenString( char* str );

int main()
{

	int x = LenString("Simone\0");

	printf("%d" ,x);

	return 0;

}


void AllocaVetString( char** vetstring, int dim )
{
	vetstring = (char**) calloc(dim,sizeof(char*));
}

int LenString( char* str )
{
	int i = 0;

	while(*(str +i ) != '\0')
	{
		i = i + 1;
	}

	return i;
}