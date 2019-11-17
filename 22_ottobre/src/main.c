/*
 * main.c
 *
 * Author: Gramegna Simone
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define DIM 5

typedef struct{

    int dim;

    int elementi[DIM];

}vettore;

int LeggiDimensione( vettore v );

void ScriviDimensione( vettore* v, int val );

int LeggiElemento( vettore v, int index );

void ScriviElemento( vettore* v, int index, int val );

// controlla se un elemento e' presente nel vettore
int check( vettore v, int dim, int v_search );

// conteggio numero presenze di un elemento
int presenze( vettore v, int dim, int elem );

// individuazione della prima posizione in cui si trova un elemento
int position( vettore v, int dim, int elem );

// funzione pe invertire gli elementi di un vettore
void InvertiVettore( vettore* v_inverso, vettore v, int dim );

// funzione per stampare il tipo di dato vettore
void StampaVettore( vettore v1, int dim );



int main()
{

    vettore v1;
    vettore v1_inverso;

    ScriviDimensione(&v1, DIM);
    ScriviDimensione(&v1_inverso, DIM);

    //assegno valori interi a v1
    ScriviElemento(&v1,0,2);
    ScriviElemento(&v1,1,2);
    ScriviElemento(&v1,2,5);
    ScriviElemento(&v1,3,4);
    ScriviElemento(&v1,4,4);

    // stampo i risultati ottenuti

    printf("Il vettore inverso e' : \n");
    InvertiVettore(&v1_inverso, v1, LeggiDimensione(v1));
    StampaVettore(v1_inverso, LeggiDimensione(v1_inverso));

    int elem;

    printf("\nInserisci un elemento che vuoi controllare nel vettore \n");
        scanf("%d" ,&elem);

    int control = check(v1,LeggiDimensione(v1),elem);

    if( control == 0 )
    {
        printf("\nL'elemento %d non e' presente nel vettore \n" ,elem);
    }
    else
    {

        int p = presenze( v1,LeggiDimensione(v1), elem );
        int pos = position(v1,LeggiDimensione(v1), elem);

        printf("\nL'elemento %d e' presente nel vettore, %d volte \n" ,elem,p);
        printf("La prima posizione in cui l'elemento %d appare nel vettore e': %d \n",elem,pos);

    }

        system("pause");
    return 0;
}

int LeggiDimensione( vettore v )
{
    return v.dim;
}

void ScriviDimensione( vettore* v, int val )
{
    v->dim = val;
}

int LeggiElemento( vettore v, int index )
{
    return v.elementi[index];
}

void ScriviElemento( vettore* v, int index, int val )
{
    v->elementi[index] = val;
}

int check( vettore v, int dim, int v_search )
{
    int i = 0;
    int check = 0;

    while( (i < dim) && (check == 0) )
    {
        if( LeggiElemento(v,i) == v_search )
        {
            check = 1;
        }

        i = i + 1;
    }

    return check;
}

int presenze( vettore v, int dim, int elem )
{

    int presenze = 0;

    int controllo = check(v,dim,elem);

    if( controllo == 1 )
    {

        int i = 0;

        while( i < dim )
        {
            if( LeggiElemento(v, i) == elem )
            {
                presenze = presenze + 1;
            }

            i = i + 1;
        }
    }

    return presenze;

}

int position( vettore v, int dim, int elem )
{

    int position = -1;

    int controllo = check(v,dim,elem);

    if( controllo == 1 )
    {
        int i = 0;

        while( (i < dim) && (position == -1) )
        {
            if( LeggiElemento(v,i) == elem )
            {
                position = i;
            }

            i = i + 1;
        }
    }

    return position;
}

void InvertiVettore( vettore* v_inverso, vettore v, int dim )
{
    int i = 0;

    while( i < dim )
    {

        int elem = LeggiElemento(v,i);

        ScriviElemento(v_inverso, dim-1-i,elem);

        i = i + 1;
    }
}

void StampaVettore( vettore v1, int dim )
{

    int i = 0;

    while( i < dim )
    {
        int elem = LeggiElemento(v1,i);
        printf(" %d " ,elem);

        i = i + 1;
    }
}
