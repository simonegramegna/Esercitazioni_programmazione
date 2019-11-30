/*
 * main.c
 *
 *  Created on: 26/nov/2019
 *      Author: Gramegna Simone
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// dimensione di caratteri massima del tipo stringa
#define DIMSTRING 50

// definisco tipo stringa
typedef char stringa[DIMSTRING];

// definisco tipo di dato studente
typedef struct{

	stringa nome;
	int matricola;

	int* voti;

}studente;

// funzione per leggere il nome
void LeggiNome( studente s1, stringa nome );

// funzione per scrivere il nome
void ScriviNome( studente* s1, stringa valore_nome );

// funzione che legge il numero di matricola
int LeggiMatricola( studente s1 );

// funzione che scrive il numero di matricola
void ScriviMatricola( studente* s1, int v_matricola );

// funzione che legge un voto dello studente
int LeggiVoto( studente s1, int index );

// funzione che scrive il voto dello studente
void ScriviVoto( studente* s1, int index, int value );

// funzione che calcola la media dei voti dello studente
float MediaVoti( studente s1 );

// funzione per stampare la media
void StampaMedia( float media );

// funzione che alloca in memoria il vettore lineare in cui sono contenuti i voti
void AllocaVoti(studente* s1, int dim );

// funzione che dealloca il vettore dei voti
void DeallocaVoti( studente* s1 );

int main()
{
	// creo nuovo studente
	studente simone;

	stringa name_student = "Simone\0";
	int numero_matricola = 666;

	// scrivo il nome dello studente e il numero di matricola

	ScriviNome(&simone, name_student);

	ScriviMatricola(&simone, numero_matricola);

	// scrivo i voti del campo studente

	int dim = 4;

	// alloco dinamicamente il vettore dei voti
	AllocaVoti(&simone, dim );

	// assegno i voti allo studente
	ScriviVoto(&simone,0,18);
	ScriviVoto(&simone,1,16);
	ScriviVoto(&simone,2,24);
	// valore  per cui finiscono i voti
	ScriviVoto(&simone,3,-1);

	// calcola la media dei voti dello studente
	float media_studente = MediaVoti(simone);

	// stampo la media
	StampaMedia(media_studente);

	// dealloco dalla memoria il vettore dei voti
	DeallocaVoti(&simone);

		system("pause");
	return 0;
}

void LeggiNome( studente s1,stringa nome )
{
	strcpy(nome,s1.nome);
}

void ScriviNome( studente* s1, stringa valore_nome )
{
	strcpy(s1->nome, valore_nome);
}

int LeggiMatricola( studente s1 )
{
	return s1.matricola;
}

void ScriviMatricola( studente* s1, int v_matricola )
{
	s1->matricola = v_matricola;
}

int LeggiVoto( studente s1, int index )
{
	int voto = 0;

	if( index >= 0 )
	{
		voto = *(s1.voti + index);
	}

	return voto;
}

void ScriviVoto( studente* s1, int index, int value )
{
	if( index >= 0 )
	{
		*(s1->voti + index) = value;
	}
}

float MediaVoti( studente s1 )
{
	int i = 0;
	int somma = 0;

	float media;

	while( LeggiVoto(s1,i) > 0 )
	{
		somma = somma + LeggiVoto(s1,i);

		i = i + 1;
	}

	media = (float) somma / i;

	return media;
}

void StampaMedia( float media )
{
	printf("La media dello studente e' %.2f \n" ,media);
}

void AllocaVoti(studente* s1, int dim )
{
	s1->voti = (int*) calloc(dim,sizeof(int));
}

void DeallocaVoti( studente* s1 )
{
	free(s1->voti);
}
