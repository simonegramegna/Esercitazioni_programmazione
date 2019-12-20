/*
 * main.c
 *
 *  Created on: 3 dic 2019
 * 
 *  Author: Gramegna Simone
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// dimensione massima della stringa
#define DIMSTRING 50

// definisco la dimesione dell'elenco degli studenti
#define NUMSTUDENTI 5

// definisco il valore sentinella per cui i voti di uno studente terminano
#define SENTINEL -1

// definizione tipo di dato stringa
typedef char stringa[DIMSTRING];

// definizione tipo di dato studente
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

// funzione ricerca lineare dello studente per nominativo
int CercaNominativo(studente elenco[], int dim, stringa nome_studente );

// funzione ricerca binaria della matricola dello studente
int CercaMatricola( studente elenco[], int dim, int numero_matricola );

// funzione per la stampa della media di uno studente
void StampaMedia( studente elenco[], int index, int dim );

// funzione per stampare i risultati ottenuti dalla ricerca per nome o per matricola
void StampaRisultati( studente elenco[], int dim, int risultato_ricerca );

// funzione per rendere minuscolo il nome cercato dall'utente
void LowerString( stringa n1 );

int main()
{

	studente elenco_studenti[NUMSTUDENTI];

	/*********studente[0]***************************/

	int numvoti_studente0 = 3;
	int matricola0 = 13;

	ScriviNome(&(elenco_studenti[0]),"simone\0");
	ScriviMatricola(&(elenco_studenti[0]), matricola0);

	AllocaVoti(&(elenco_studenti[0]), numvoti_studente0);

	ScriviVoto(&(elenco_studenti[0]), 0, 25);
	ScriviVoto(&(elenco_studenti[0]), 1, 28);
	ScriviVoto(&(elenco_studenti[0]), 2, SENTINEL);

	/***************studente[1]****************************/

	int numvoti_studente1 = 4;
	int matricola1 = 63;

	ScriviNome(&(elenco_studenti[1]),"fabio\0");
	ScriviMatricola(&(elenco_studenti[1]), matricola1);

	
	AllocaVoti(&(elenco_studenti[1]), numvoti_studente1);

	ScriviVoto(&(elenco_studenti[1]), 0, 25);
	ScriviVoto(&(elenco_studenti[1]), 1, 30);
	ScriviVoto(&(elenco_studenti[1]), 2, 26);
	ScriviVoto(&(elenco_studenti[1]), 3, SENTINEL);

	/***********studente[2]*****************************/

	int numvoti_studente2 = 2;
	int matricola2 = 45;

	ScriviNome(&(elenco_studenti[2]),"luigi\0");
	ScriviMatricola(&(elenco_studenti[2]), matricola2);

	AllocaVoti(&(elenco_studenti[2]), numvoti_studente2);

	ScriviVoto(&(elenco_studenti[2]), 0, 25);
	ScriviVoto(&(elenco_studenti[2]), 1, SENTINEL);
	
	/***********studente[3]***************************/

	int numvoti_studente3 = 2;
	int matricola3 = 73;

	ScriviNome(&(elenco_studenti[3]),"giuseppe\0");
	ScriviMatricola(&(elenco_studenti[3]), matricola3);

	AllocaVoti(&(elenco_studenti[3]), numvoti_studente3);

	ScriviVoto(&(elenco_studenti[3]), 0, 25);
	ScriviVoto(&(elenco_studenti[3]), 1, SENTINEL);

	/**********studente[4]*************************/

	int numvoti_studente4 = 5;
	int matricola4 = 63;

	ScriviNome(&(elenco_studenti[4]),"michela\0");
	ScriviMatricola(&(elenco_studenti[4]), matricola4);

	// 
	AllocaVoti(&(elenco_studenti[4]), numvoti_studente4);

	ScriviVoto(&(elenco_studenti[4]), 0, 25);
	ScriviVoto((&elenco_studenti[4]), 1, 27);
	ScriviVoto(&(elenco_studenti[4]), 2, 22);
	ScriviVoto((&elenco_studenti[4]), 3, 21);
	ScriviVoto(&(elenco_studenti[4]), 4, SENTINEL);

	int scelta;

	printf("Premi 1 per effettuare la ricerca per nome\nPremi 2 per effettura la ricerca per matricola\nPremi 3 per uscire \n");
		scanf("%d" ,&scelta);

	if( scelta == 1 )
	{

		stringa nome_ricerca;

		printf("Inserisci il nome dello studente da cercare \n");
			scanf("%s" ,nome_ricerca);

			LowerString(nome_ricerca);

			int risultato_cerca_nome = CercaNominativo(elenco_studenti, NUMSTUDENTI, nome_ricerca);

			StampaRisultati(elenco_studenti, NUMSTUDENTI, risultato_cerca_nome);
			StampaMedia( elenco_studenti, risultato_cerca_nome, NUMSTUDENTI	);
	
	}
	else if( scelta == 2 )
	{

		int matricola_ricerca;

		printf("Inserisci la matricola dello studente da cercare \n");
			scanf("%d" ,matricola_ricerca);

			int risultato_cerca_matricola = CercaMatricola(elenco_studenti, NUMSTUDENTI, matricola_ricerca);

			StampaRisultati(elenco_studenti, NUMSTUDENTI, risultato_cerca_matricola);
			StampaMedia(elenco_studenti, risultato_cerca_matricola, NUMSTUDENTI);

	}
	else
	{
		printf("Sto uscendo dal programma...\n");
	}
	


	system("pause");
return 0;
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

	// leggo i voti finche non trovo un vlaore sentinella minore di 0
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
	// valore che mi restituira la posizione dell'elemento trovato
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

		if( numero_matricola > LeggiMatricola(elenco[medio]) )
		{
			inf = medio + 1;
		}
		else if( numero_matricola < LeggiMatricola(elenco[medio]) )
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

void StampaRisultati( studente elenco[], int dim, int risultato_ricerca )
{
	if( risultato_ricerca > -1 && risultato_ricerca < dim )
	{
		printf("Lo studente selezionato e' presente nella %d posizione del vettore degli studenti\n");
	}
	else
	{
		printf("Lo studente selezionato non e' presente nel vettore \n");
	}
}

void StampaMedia( studente elenco[], int index, int dim )
{
	if( index > -1 && index < dim )
	{

		float media_studente = MediaVoti( elenco[index] );

		printf("La media dello studente selezionato e' %.2f \n" ,media_studente);

	}
}

void LowerString( stringa n1 )
{

	int i = 0;

	while( n1[i] != '\0' )
	{

		n1[i] = tolower(n1[i]);

		i = i + 1;

	}

}






