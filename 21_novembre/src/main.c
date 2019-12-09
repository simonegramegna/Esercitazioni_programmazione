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

#define DIM 3

// funzione per prendere in input una stringa di dimensione N

void InputString(char** VetString, int dim);

int CalcolaLunghezza( char* str);

int main()
{

	char** stringhe;

	stringhe = (char**) calloc(DIM,sizeof(char*));

	InputString(stringhe, DIM );

	return 0;


}

int CalcolaLunghezza( char* str )
{
	int i = 0;
	int len;

	while(*(str+i) != '\0')
	{
		i = i + 1;
	}

	len = i;

	return len;
}

void InputString(char** VetString, int dim)
{
	int i = 0;

	while( i < dim )
	{

		printf("Inserisci una stringa \n");
			scanf("%s" ,*(VetString + i));

		i = i + 1;
	}
}
