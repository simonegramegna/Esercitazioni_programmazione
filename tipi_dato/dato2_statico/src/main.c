/*
 * main.c
 *
 *  Created on: 22 nov 2019
 *
 *  Author: Gramegna Simone
 *
 *  definizione di funzioni base tipo di dato matrice
 * 
 * La matrice ha due campi interi (righe e colonne) e un campo 
 * dato da un vettore reale di dimensione massima MAX
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

int main()
{

    // creo la matrice
    matrice matrix;

    // scrivo righe e colonne della matrice

    int righe = 2;
    int colonne = 2;


    ScriviRighe(&matrix, righe);
    ScriviColonne(&matrix, colonne);

    // assegno valori alla matrice

    ScriviElemento(&matrix, 0,0, 1.1);
    ScriviElemento(&matrix, 0,1, 2.1);
    ScriviElemento(&matrix, 1,0, 3.1);
    ScriviElemento(&matrix, 1,1, 4.1);


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


