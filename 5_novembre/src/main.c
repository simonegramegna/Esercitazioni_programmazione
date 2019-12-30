/*
 * main.c
 *
 *  Esercitazione 5 Novembre
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
#define R1 2
#define C1 2
#define R2 2
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

// funzione per calcolare il prodotto scalare tra numero reale e una matrice
void scalare( matrice* m_scalare, matrice m, int righe, int colonne, float scal );

// fuunzione che somma due matrici
void somma( matrice* m_somma, matrice m1, matrice m2, int r1, int c1, int r2, int c2 );

// funzione che stampa una matrice
void StampaMatrice( matrice m_stampa, int righe, int colonne );

int main()
{

    matrice matrix;
    matrice scalare0;
    matrice matrix2;
    matrice somma0;

    // scrivo righe e colonne della prima matrice

    ScriviRighe(&matrix, R1);
    ScriviColonne(&matrix, C1);

    // assegno valori alla prima matrice

    ScriviElemento(&matrix,0,0,18.1);
    ScriviElemento(&matrix,0,1,15.4);
    ScriviElemento(&matrix,1,0,11.1);
    ScriviElemento(&matrix,1,1,16.1);


    // scrivo righe e colonne della matrice prodotto scalare
    ScriviRighe(&scalare0, R1);
    ScriviColonne(&scalare0, C1);

    float s1 = 6.6;

    // prodotto scalare di s1 per la prima matrice
        scalare(&scalare0, matrix, LeggiRighe(matrix), LeggiColonne(matrix), s1 );

    // scrivo righe e colonne della prima matrice
    ScriviRighe(&matrix2, R2);
    ScriviColonne(&matrix2, C2);

    // assegno valori alla seconda matrice
    ScriviElemento(&matrix,0,0,8.1);
    ScriviElemento(&matrix,0,1,5.4);
    ScriviElemento(&matrix,1,0,1.1);
    ScriviElemento(&matrix,1,1,6.1);

    // somma delle due matrici
        somma(&somma0, matrix, matrix2, R1, C1, R2, C2 );

    printf("La prima matrice e': \n");
        StampaMatrice(matrix, R1, C1);
    
    printf("\nLa seconda matrice e': \n");
        StampaMatrice(matrix2,R2,C2);


    // stampo i risultati ottenuti
    printf("\nIl prodotto scalare tra la prima matrice e %.2f equivale a: \n" ,s1);
        StampaMatrice(scalare0,R1,C1);

    printf("\nLa somma tra le due matrici matrix e matrix2 equivale a: \n");
        StampaMatrice(somma0,R1,C1);

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

void scalare( matrice* m_scalare, matrice m, int righe, int colonne, float scal )
{

    int i = 0;

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

void StampaMatrice( matrice m_stampa, int righe, int colonne )
{

    int i = 0;

    while( i < righe )
    {

        int j = 0;

        while( j < colonne )
        {
            printf(" %.2f \n", LeggiElemento(m_stampa, i, j) );

            j = j + 1;
        }

       i = i + 1;
    }
}
