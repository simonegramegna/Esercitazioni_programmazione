/*
 * main.c
 *
 *  Created on: 14 nov 2019
 *  Author: Gramegna Simone
 *
 */
#include <stdio.h>
#include <stdlib.h>

// definisco la dimensione massima del campo elementi
#define MAX 625

// definisco tipo di dato
typedef struct{

    int righe;
    int colonne;

    float elementi[MAX];

}matrice;

// funzione lettura righe
int LeggiRighe( matrice m1 );

// funzione scrittura righe
void ScriviRighe( matrice* m1, int valore );

// funzione lettura colonne
int LeggiColonne( matrice m1 );

// funzione scrittura colonne
void ScriviColonne( matrice* m1, int valore );

// funzione per lettura di un elemento
float LeggiElemento( matrice  m1, int i_riga, int i_colonna );

// funzione scrittura elementi
void ScriviElemento( matrice* m1, int i_riga, int i_colonna, float valore );

// funzione prodotto riga per colonna
float ProdottoRigaColonna( matrice m1, matrice m2, int riga, int colonna );

// funzione prodotto tra due matrici
void Prodotto( matrice* prodotto, matrice m1, matrice m2, int r1, int c1, int r2, int c2 );

// funzione matrice trasposta
void Trasposta( matrice* trasposta, matrice m, int r1, int c1 );

// funzione che stampa una matrice
void StampaMatrice( matrice m_stampa, int righe, int colonne );

int main()
{

	// vreo la matrice m1
	matrice m1;

	int righe = 2;
	int colonne = 3;

	ScriviRighe(&m1,righe);
	ScriviColonne(&m1,colonne);

	// assegno valori a m1
	ScriviElemento(&m1, 0, 0, 8.1);
	ScriviElemento(&m1, 0, 1, 9.1);
	ScriviElemento(&m1, 0, 2, 5.5);
	ScriviElemento(&m1, 1, 0, 1.1);
	ScriviElemento(&m1, 1, 1, 7.1);
	ScriviElemento(&m1, 1, 2, 4.4);

	// calcolo la matrice trasposta di m1
	matrice m_trasposta;

	Trasposta(&m_trasposta,m1,LeggiRighe(m1),LeggiColonne(m1) );

	// creo la matrice m2
	matrice m2;

	int righe2 = 3;
	int colonne2 = 2;

	ScriviRighe(&m2, righe2);
	ScriviColonne(&m2, colonne2);

	// assegno valori a m2

	ScriviElemento(&m2, 0, 0, 8.1);
	ScriviElemento(&m2, 0, 1, 9.1);
	ScriviElemento(&m2, 1, 0, 1.1);
	ScriviElemento(&m2, 1, 1, 6.1);
	ScriviElemento(&m2, 2, 0, 2.1);
	ScriviElemento(&m2, 2, 1, 7.1);

	// calcolo il prodotto tra m1 ed m2

	matrice m_prodotto;

	Prodotto(&m_prodotto,m1,m2,LeggiRighe(m1),LeggiColonne(m1),LeggiRighe(m2),LeggiColonne(m2));


	// stampo i risultati ottenuti

	printf("Il prodotto tra le matrici m1 ed m2 e': \n");
		StampaMatrice(m_prodotto,LeggiRighe(m_prodotto),LeggiColonne(m_prodotto));

	printf("\n La matrice trasposta di m1 e' \n");
		StampaMatrice(m_trasposta,LeggiRighe(m_trasposta),LeggiColonne(m_trasposta));

		system("pause");
	return 0;
}

int LeggiRighe( matrice m1 )
{
    return m1.righe;
}

void ScriviRighe( matrice* m1, int valore )
{
    m1->righe = valore;
}

int LeggiColonne( matrice m1 )
{
    return m1.colonne;
}

void ScriviColonne( matrice* m1, int valore )
{
    m1->colonne = valore;
}

float LeggiElemento( matrice  m1, int i_riga, int i_colonna )
{

    int index = i_riga*LeggiColonne(m1) + i_colonna;
    return m1.elementi[index];

}

void ScriviElemento( matrice* m1, int i_riga, int i_colonna, float valore )
{
    int index = i_riga*LeggiColonne(*m1) + i_colonna;
    m1->elementi[index] = valore;

}

float ProdottoRigaColonna( matrice m1, matrice m2, int riga, int colonna )
{

    float somma = 0;
    int i = 0;

    while( i < LeggiColonne(m1) )
    {

        float prodotto = LeggiElemento(m1, riga, i) * LeggiElemento(m2, i, colonna);
        somma = somma + prodotto;

        i = i + 1;
    }

    return somma;
}

void Prodotto( matrice* prodotto, matrice m1, matrice m2, int r1, int c1, int r2, int c2 )
{

    if( (c1 == r2) && (r1 == c2) )
    {

        ScriviRighe(prodotto, r1);
        ScriviColonne(prodotto, c2);

        int i = 0;

        while( i < LeggiRighe((*prodotto)) )
        {

            int j = 0;

            while( j < LeggiColonne((*prodotto)) )
            {

                float prc = ProdottoRigaColonna(m1, m2, i, j);
                ScriviElemento(prodotto, i, j, prc );

                j = j + 1;
            }

            i = i + 1;
        }
    }
}

void Trasposta( matrice* trasposta, matrice m, int r1, int c1 )
{

    ScriviRighe(trasposta, c1);
    ScriviColonne(trasposta, r1);

    int i = 0;

    while( i < LeggiRighe((*trasposta)) )
    {
        int j = 0;

        while( j < LeggiColonne((*trasposta)) )
        {

            float elem = LeggiElemento(m, j, i);
            ScriviElemento(trasposta,i ,j ,elem);

            j = j + 1;

        }
        i = i + 1;
    }
}


void StampaMatrice( matrice m_stampa, int righe, int colonne )
{

    int i = 0;

    while( i < righe )
    {

        int j = 0;

        while( j < colonne )
        {
            printf(" %.2f ", LeggiElemento(m_stampa, i, j) );

            j = j + 1;
        }

       i = i + 1;
    }
}

