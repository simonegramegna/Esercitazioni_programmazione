/*
 * main.c
 *
 *  Created on: 28/nov/2019
 *      Author: Gramegna Simone
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// dimensione massima di caratteri del tipo stringa
#define MAX 50

// dimensione elenco degli studenti
#define DIM 3

// definisco tipo di dato stringa
typedef char stringa[MAX];

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

// funzione che alloca in memoria il vettore lineare in cui sono contenuti i voti
void AllocaVoti(studente* s1, int dim );

// funzione che dealloca il vettore dei voti
void DeallocaVoti( studente* s1 );

// funzione per cercare uno studente con un numero di matricola
int CercaMatricola(studente elenco[], int dim, int n_matricola);

// funzione per cercare uno studente per nominativo
int CercaNome( studente elenco[], int dim, stringa nome_studente );

// funzione per stampare la presenza di un nome
void StampaPresenzaNome(studente elenco[], int dim, int index);

// funzione per stampare la presenza di un numero di matricola
void StampaPresenzaMatricola( studente elenco[], int dim, int index );

int main()
{

	// assegno valori agli studenti
	studente simone;
	studente antonio;
	studente luigi;


	ScriviNome(&simone, "simone\0");
	ScriviMatricola(&simone, 666 );

	ScriviNome(&antonio,"anto\0");
	ScriviMatricola(&antonio, 200);

	ScriviNome(&luigi,"gigi\0");
	ScriviMatricola(&luigi,500);

	// dichiaro l'elenco degli studenti
	studente elenco_studenti[DIM] = { simone, antonio, luigi };

	// SISTEMA!!!!!

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

void AllocaVoti(studente* s1, int dim )
{
	s1->voti = (int*) calloc(dim,sizeof(int));
}

void DeallocaVoti( studente* s1 )
{
	free(s1->voti);
}

int CercaMatricola(studente elenco[], int dim, int n_matricola)
{
	int i = 0;
	int index_found = -1;

	while( i < dim && index_found == -1 )
	{

		if( LeggiMatricola(elenco[i]) == n_matricola )
		{
			index_found = i;
		}

		i = i + 1;
	}

	return found;
}

int CercaNome( studente elenco[], int dim, stringa nome_studente )
{

	int i = 0;
	int index_found = -1;

	while( i < dim && index_found == -1 )
	{

		stringa nome_confronto;

		LeggiNome(elenco[i],nome_confronto);

		int string_compare = strcmp(nome_confronto,nome_studente);

		if( string_compare == 0 )
		{
			index_found = i;
		}

		i = i + 1;
	}

	return found;
}

void StampaPresenzaNome(studente elenco[], int dim, int index)
{

	if( index > -1 && index < dim )
	{
		stringa nome_stampa = LeggiMatricola(elenco[index]);

		printf("La matricola %s cercata e' presente nel vettore \n" ,nome_stampa);
	}
	else
	{
		printf("La matricola inserita non e' presente nel vettore \n");
	}
	

}



