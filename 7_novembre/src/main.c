/*
 * main.c
 *
 *  Esercitazione 7 Novembre
 *
 *  Author: Gramegna Simone
 *
 */
#include <stdio.h>
#include <stdlib.h>

// definisco le dimensioni massime di righe e colonne del tipo di dato matrice
#define MAXRIGHE 200
#define MAXCOLONNE 200

// definisco le dimensioni effettive delle due matrici

// numero righe e colonne prima matrice
#define R1 2
#define C1 3
// numero righe e colonne seconda matrice
#define R2 3
#define C2 2

// definisco tipo di dato matrice
typedef struct{

    int righe;
    int colonne;

    float elementi[MAXRIGHE][MAXCOLONNE];

}matrice;

// funzione per leggere le righe
int LeggiRighe( matrice m );

// funzione per scrivere le righe
void ScriviRighe( matrice* m, int r_val );

// funzione per leggere le colonne
int LeggiColonne( matrice m );

// funzione per scrivere le colonne
void ScriviColonne( matrice* m, int c_val );

// funzione per leggere un elemento
float LeggiElemento( matrice m, int riga, int colonna );

// funzione per scrivere un elemento
void ScriviElemento( matrice* m, int riga, int colonna, float elem );

// funzione matrice trasposta
void Trasposta( matrice* trasposta, matrice m, int r1, int c1 );

// funzione prodotto riga per colonna
float ProdottoRigaColonna( matrice m1, matrice m2, int riga, int colonna );

// funzione prodotto tra due matrici
void Prodotto( matrice* prodotto, matrice m1, matrice m2, int r1, int c1, int r2, int c2 );

// funzione che stampa una matrice
void StampaMatrice( matrice m_stampa, int righe, int colonne );

int main()
{

    matrice m1;
    matrice m2;
    matrice m_trasposta;
    matrice m_prodotto;

    ScriviRighe(&m1,R1);
    ScriviColonne(&m1,C1);

    // assegno valori alla prima matrice
    ScriviElemento(&m1,0,0,8.1);
    ScriviElemento(&m1,0,1,5.4);
    ScriviElemento(&m1,0,2,2.1);
    ScriviElemento(&m1,1,0,1.1);
    ScriviElemento(&m1,1,1,6.1);
    ScriviElemento(&m1,1,2,4.1);


    ScriviRighe(&m2,R2);
    ScriviColonne(&m2,C2);

    // assegno valori alla seconda matrice

    ScriviElemento(&m2,0,0,5.1);
    ScriviElemento(&m2,0,1,2.2);
    ScriviElemento(&m2,1,0,7.1);
    ScriviElemento(&m2,1,1,9.4);
    ScriviElemento(&m2,2,0,3.1);
    ScriviElemento(&m2,2,1,1.7);

    // calcolo il prodotto di m1 * m2
    Prodotto(&m_prodotto,m1,m2,R1,C1,R2,C2);

    // calcolo la matrice trasposta di m1
    Trasposta(&m_trasposta,m1,R1,C1);


    // stampo i risultati ottenuti

    printf("La matrice trasposta di m1 e': \n");
        StampaMatrice( m_trasposta, LeggiRighe(m_trasposta), LeggiColonne(m_trasposta) );

    printf("\n Il prodotto delle due matrici m1 ed m2 e'\n");
        StampaMatrice(m_prodotto,LeggiRighe(m_prodotto), LeggiColonne(m_prodotto) );

    system("pause");
return 0;
}

int LeggiRighe( matrice m )
{
    return   m.righe;
}

void ScriviRighe( matrice* m, int r_val )
{
    m->righe = r_val;
}

int LeggiColonne( matrice m )
{
    return  m.colonne;
}

void ScriviColonne( matrice* m, int c_val )
{
    m->colonne = c_val;
}

float LeggiElemento( matrice m, int riga, int colonna )
{
    return  m.elementi[riga][colonna];
}

void ScriviElemento( matrice* m, int riga, int colonna, float elem )
{
    m->elementi[riga][colonna] =  elem;
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

// funzione prodotto riga per colonna
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
