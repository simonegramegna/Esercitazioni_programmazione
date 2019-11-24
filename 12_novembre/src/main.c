/*
 * main.c
 *
 *  Created on: 12 nov 2019
 *
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

// fuunzione che somma due matrici
void somma( matrice* m_somma, matrice m1, matrice m2, int r1, int c1, int r2, int c2 );

// funzione per calcolare il prodotto scalare tra numero reale e una matrice
void p_scalare( matrice* m_scalare, matrice m,  float scal );

// funzione che stampa una matrice
void StampaMatrice( matrice m_stampa, int righe, int colonne );

int main()
{

	matrice m1;

	int r1 = 2;
	int c1 = 2;

	ScriviRighe(&m1,r1);
	ScriviColonne(&m1,c1);

	// assegno valori alla prima matrice

	ScriviElemento(&m1, 0,0, 1.1);
	ScriviElemento(&m1, 0,1, 2.1);
	ScriviElemento(&m1, 1,0, 3.1);
	ScriviElemento(&m1, 1,1, 4.1);

	float s1 = 11.1;

	// eseguo il prodotto scalare della matrime m1 per s1

	matrice m_scalare;

	p_scalare(&m_scalare,m1,s1);

	// creo la matrice m2 e assegno i valori a m2
	matrice m2;

	int r2 = 2;
	int c2 = 2;

	ScriviRighe(&m2,r2);
	ScriviColonne(&m2,c2);

	ScriviElemento(&m2, 0,0, 8.1);
    ScriviElemento(&m2, 0,1, 9.1);
    ScriviElemento(&m2, 1,0, 1.1);
    ScriviElemento(&m2, 1,1, 7.1);

    // eseguo la somma delle matrici m1 ed m2

    matrice m_somma;

    somma(&m_somma, m1, m2, LeggiRighe(m1), LeggiColonne(m1), LeggiRighe(m2), LeggiColonne(m2) );

    // stampo i risultati ottenuti

    printf("\n La matrice data dalla somma delle matrici m1 ed md e' \n");
    	StampaMatrice( m_somma,LeggiRighe(m_somma),LeggiColonne(m_somma) );

    printf("La matrice data dal prodotto scalare tra m1 e %f e' \n",s1);
    	StampaMatrice( m_scalare,LeggiRighe(m_scalare),LeggiColonne(m_scalare));

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

void somma( matrice* m_somma, matrice m1, matrice m2, int r1, int c1, int r2, int c2 )
{

    // posso sommare le due matrici solo se hanno stessa dimensione
    if( (c1 == c2) && (r1 == r2) )
    {

        ScriviRighe(m_somma, r1);
        ScriviColonne(m_somma, c1);

        int i = 0;

        while( i < r1 )
        {
            int j = 0;

            while( j < c1 )
            {
                float somma;

                somma = LeggiElemento(m1, i, j) + LeggiElemento(m2, i, j);

                ScriviElemento( m_somma, i, j, somma );

                j = j + 1;
            }

            i = i + 1;
        }
    }
}

void p_scalare( matrice* m_scalare, matrice m, float scal )
{

    int i = 0;

    ScriviRighe(m_scalare,LeggiRighe(m));
    ScriviColonne(m_scalare,LeggiColonne(m));

    while( i < LeggiRighe(m) )
    {
        int j = 0;

        while( j < LeggiColonne(m) )
        {

            float prodotto_scalare = scal * LeggiElemento(m ,i, j);
            ScriviElemento(m_scalare, i, j, prodotto_scalare);

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
