/*
 * main.c
 *
 *  Created on: 19 nov 2019
 *  Author: Gramegna Simone
 */

#include <stdio.h>
#include <stdlib.h>

// definisco tipo di dato matrice con tre campi
typedef struct{

    int righe;
    int colonne;

    float** elementi;

}matrice;

// funzione lettura righe
int LeggiRighe( matrice m1 );

// funzione scrittura righe
void ScriviRighe( matrice* m1, int valore );

// funzione lettura colonne
int LeggiColonne( matrice m1 );

// funzione scrittura colonne
void ScriviColonne( matrice* m1, int valore );

// funzione lettura elemento
float LeggiElemento( matrice m1,int i_riga, int i_colonna );

// funzione scrittura elemento
void ScriviElemento( matrice* m1, int i_riga, int i_colonna, float valore );

// funzione per allocare gli elementi della matrice in memoria
void Alloca( matrice* m1 );

// funzione per delallocare gli elementi della matrice in memoria
void Dealloca( matrice* m1 );

// funzione per la somma riga per riga
float somma_riga( matrice m1, int i_riga );

// funzione somma colonna per colonna
float somma_colonna( matrice m1, int i_colonna );

// funzione somma prima diagonale
float somma_d1( matrice m1 );

// funzione somma seconda diagonale
float somma_d2( matrice m1 );

// funzione controllo diagonali
int diagonali_controllo( matrice m1 );

// funzione controllo righe
int righe_controllo( matrice m1 );

// funzione controllo colonne
int colonne_controllo( matrice m1 );

// funzione per inserire valori rand nella matrice
void rand_matrice( matrice* m1 );


// funzione che determina se la matrice e' un quadrato magico
int q_magico( matrice m1 );

int main()
{

    matrice mat;

    // scrivo righe e colonne della matrice
    int dim = 3;

    ScriviRighe(&mat,dim);
    ScriviColonne(&mat,dim);

    // alloco la matrice

    Alloca(&mat);

    // assegno valori alla matrice

    rand_matrice(&mat);


    int q = q_magico(mat);

    if( q == 1 )
    {
        printf("La matrice generata casualmente e' un quadrato magico \n");
    }
    else
    {
        printf("La matrice generata casualmente non e' un quadrato magico \n");
    }

    // dealloco la matrice
    Dealloca(&mat);

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

float LeggiElemento( matrice m1,int i_riga, int i_colonna )
{
    float elem = *( *( m1.elementi + i_riga ) + i_colonna );
    return elem;
}

void ScriviElemento( matrice* m1, int i_riga, int i_colonna, float valore )
{

    *( *( m1->elementi + i_riga ) + i_colonna ) = valore;

}


void Alloca( matrice* m1 )
{
    // alloco n puntatori a float nel vettore bidimensionale
    m1->elementi = (float**) malloc(LeggiRighe(*m1)*sizeof(float*) );

    int i = 0;

    while( i < LeggiRighe(*m1) )
    {

        *(m1->elementi + i) = (float*) malloc(LeggiColonne(*m1) * sizeof(float) );

        i = i + 1;
    }
}

void Dealloca( matrice* m1 )
{

    int i = 0;

    // libero la memoria allocata a ogni puntatore del veettore
    while( i < LeggiRighe(*m1) )
    {

        free( *(m1->elementi + i) );

        i = i + 1;
    }
    // libero la memoria allocata alla matrice
    free(m1->elementi);
}

float somma_riga( matrice m1, int i_riga )
{
    int i = 0;
    float somma = 0;

    while( i < LeggiColonne(m1) )
    {
        somma = somma + LeggiElemento(m1,i_riga,i);
        i = i + 1;
    }

    return somma;
}

float somma_colonna( matrice m1, int i_colonna )
{
    int i = 0;
    float somma = 0;

    while( i < LeggiRighe(m1) )
    {
        somma = somma + LeggiElemento(m1,i,i_colonna);

        i = i + 1;
    }

    return somma;
}

float somma_d1( matrice m1 )
{
    int i = 0;
    float somma = 0;

    while( i < LeggiColonne(m1) )
    {
        somma = somma + LeggiElemento(m1,i,i);

        i = i + 1;
    }

    return somma;
}

float somma_d2( matrice m1 )
{
    int i = LeggiColonne(m1) - 1;

    float somma = 0;

    while( i >= 0 )
    {
        somma = somma + LeggiElemento(m1,i,i);
        i = i - 1;
    }

    return somma;
}

int diagonali_controllo( matrice m1 )
{
    int controllo = 0;

    float d1 = somma_d1(m1);
    float d2 = somma_d2(m1);

    if( d1 == d2 )
    {
        controllo = 1;
    }
    return controllo;
}

int righe_controllo( matrice m1 )
{
    int i = 1;
    int c0 = 0;
    int controllo = 1;

    float compare = somma_riga(m1,c0);

    while( i < LeggiRighe(m1) && controllo == 1 )
    {

        float somma = somma_riga(m1,i);

        if( somma != compare )
        {
            controllo = 0;
        }

        i = i + 1;
    }
    return controllo;
}

int colonne_controllo( matrice m1 )
{
    int i = 1;
    int c0 = 0;
    int controllo = 1;

    float compare = somma_colonna(m1,c0);

    while( i < LeggiColonne(m1) && controllo == 1 )
    {
        float somma = somma_colonna(m1,i);

        if( somma != compare )
        {
            controllo = 0;
        }

        i = i + 1;
    }

    return controllo;
}

void rand_matrice( matrice* m1 )
{
    int i = 0;

    while( i < LeggiRighe(*m1) )
    {
        int j = 0;

        while( j < LeggiColonne(*m1) )
        {

            float num = (float) rand();
            ScriviElemento(m1,i,j,num);

            j = j + 1;
        }
        i = i + 1;
    }
}

int q_magico( matrice m1 )
{
    int cr = righe_controllo(m1);
    int cc = colonne_controllo(m1);
    int cd = diagonali_controllo(m1);

    int controllo;

    if( (cd == cc) && (cc == cr) && (cd == cr) )
    {
        controllo = 1;
    }
    else
    {
        controllo = 0;
    }
    return controllo;
}


