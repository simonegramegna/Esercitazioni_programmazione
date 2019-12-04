/*
 * main.c
 *
 *  Created on: 3 dic 2019
 *      Author: Gramegna Simone
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIMSTRING 50

typedef char stringa[DIMSTRING];

typedef struct{

	stringa nome;
	int matricola;
	int* voti;

}studente;

// funzione lettura nome dello studente
void LeggiNome( studente s1, stringa nome );

// funzione scrittura nome dello studente
void ScriviNome( studente* s1, stringa nome_valore );

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

// funzione che alloca in memoria il vettore lineare in cui sono contenuti i voti
void AllocaVoti(studente* s1, int dim );

// funzione che dealloca il vettore dei voti
void DeallocaVoti( studente* s1 );

// funzione per allocare dinamicamente vettore di studenti
void AllocaStudenti(studente* s1, int num_studenti );

// funzione per deallocare il vettore di studenti
void DeallocaStudenti( studente* s1 );


// funzione ricerca lineare dello studente per nominativo
int CercaNominativo(studente elenco[], int dim, stringa nome_studente );

// funzione ricerca binaria della matricola dello studente
int CercaMatricola( studente elenco[], int dim, int numero_matricola );

int main()
{

}

void LeggiNome( studente s1, stringa nome )
{
	strcpy( nome,s1.nome );
}

void ScriviNome( studente* s1, stringa nome_valore )
{
	strcpy( s1->nome, nome_valore );
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
	int c = 0;
	int somma = 0;
	float media;

	while( LeggiVoto(s1,c) > 0 )
	{
		somma = somma + LeggiVoto(s1,c);

		c = c + 1;
	}

	media = (float) somma / c;

	return media;
}

void AllocaVoti(studente* s1, int dim )
{
	s1->voti = (int*) calloc(dim,sizeof(int));
}

void DeallocaVoti( studente* s1 )
{
	free(s1->voti);
}

void AllocaStudenti(studente* s1, int num_studenti )
{
	s1 = (studente*) calloc(num_studenti, sizeof(studente) );
}

void DeallocaStudenti( studente* s1 )
{
	free(s1);
}

int CercaNominativo(studente elenco[], int dim, stringa nome_studente )
{
	int found = -1;

	int i = 0;

	while( i < dim && found == -1 )
	{

		stringa name_i;
		LeggiNome( elenco[i], name_i );

		// la funzione ritorna zero se le due stringhe prese in input sono uguali
		int name_compare = strcmp(name_i, nome_studente);

		if( name_compare == 0 )
		{
			found = i;
		}

		i = i + 1;
	}

	return found;
}

int CercaMatricola( studente elenco[], int dim, int numero_matricola )
{
	// valore che mi restituir� la posizione dell'elemento trovato
	int position = -1;

	// definisco l'estremo inferiore e superiore iniziale
	int sup = dim - 1;
	int inf = 0;

	/*
	 * Continuo ficnhe non trovo l'elemento
	 * e il valore dell'estremo inferiore non supera
	 * il valore dell'estremo superiore
	 *
	 */
	while( (inf<=sup) && (position == -1) )
	{
		// calcolo l'indice medio
		int medio = (int) (inf+sup) / 2;

		if( numero_matricola > elenco[medio] )
		{
			inf = medio + 1;
		}
		else if( numero_matricola < elenco[medio] )
		{
			sup = medio - 1;
		}
		else
		{
			position = medio;
		}
	}

	return position;
}












