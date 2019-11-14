/*
 * main.c
 *
 * Esercitazione 17 ottobre
 *
 * author: Gramegna Simone
 *
 */

#include <stdio.h>
#include <stdlib.h>

// dimensione del vettore
#define N 10

// funzione per cercare numeri positivi
int CercaPositivi( int vett[], int dim );

// funzione per cercare numeri negativi
int CercaNegativi( int vett[], int dim );

// funzione per cercare numeri nulli
int CercaNulli( int vett[], int dim );

// funzione per cercare numeri pari
int CercaPari( int vett[], int dim );

// funzione per cercare numeri dispari
int CercaDispari( int vett[], int dim );

// funzione per il controllo della crescenza della funzione
int Crescente( int vett[], int dim );

// funzione per il controllo della decrescenza della funzione
int Decrescente( int vett[], int dim );

// funzione per stampare i risultati
void StampaRisultati( int vet[], int dim );

// funzione per prendere in input il vettore
void Vetinput( int vet[], int dim );

int main()
{

    int vettore[N];

        // prendo in input il vettore
        Vetinput(vettore, N);

        // stampo i risultati ottenuti dal vettore
        StampaRisultati(vettore,N);

    system("pause");

    return 0;
}

int CercaPositivi( int vett[], int dim )
{
    int i = 0;
    int Npositivi = 0;

    while( i < dim )
    {
        if( vett[i] > 0 )
        {
            Npositivi = Npositivi + 1;
        }

        i = i + 1;
    }

    return Npositivi;

}

int CercaNegativi( int vett[], int dim )
{
    int i = 0;
    int negativi = 0;

    while( i < dim )
    {
        if( vett[i] < 0 )
        {
            negativi = negativi + 1;
        }

        i = i + 1;
    }

    return negativi;

}

int CercaNulli( int vett[], int dim )
{
    int i = 0;
    int nulli = 0;

    while( i < dim )
    {
        if( vett[i] == 0 )
        {
            nulli = nulli + 1;
        }

        i = i + 1;
    }

    return nulli;

}

int CercaPari( int vett[], int dim )
{
    int i = 0;
    int pari = 0;

        while( i< dim )
        {
            if(  vett[i] % 2 == 0)
            {
                pari = pari + 1;
            }

            i = i + 1;
        }

    return pari;
}

int CercaDispari( int vett[], int dim )
{

    int i = 0;
    int dispari = 0;

        while( i< dim )
        {
            if(  vett[i] % 2 != 0)
            {
                dispari = dispari + 1;
            }

            i = i + 1;
        }

    return dispari;

}


int Crescente( int vett[], int dim)
{
    int i = 1;
    int crescente = 0;

        while( i < dim )
        {
            if( vett[i] > vett[i-1] )
            {
                crescente = 1;
            }
            else
            {
                crescente = 0;
            }

            i = i + 1;
        }

    return crescente;
}

int Decrescente( int vett[], int dim )
{
    int i = 1;
    int decrescente = 0;

    while( i < dim )
    {

        if( vett[i] < vett[i-1] )
        {
            decrescente = 1;
        }
        else
        {
            decrescente = 0;
        }

        i = i + 1;
    }

    return decrescente;
}

void Vetinput( int vet[], int dim )
{

    int i = 0;

    do{

        printf("Inserisci un numero intero \n");
            scanf("%d" ,&vet[i]);

        i = i + 1;
    }
    while( i < dim );

}

void StampaRisultati( int vet[], int dim )
{

    int positivi = CercaPositivi(vet, dim);
    int negativi = CercaNegativi(vet, dim);
    int nulli = CercaNulli(vet, dim);
    int pari = CercaPari(vet, dim);
    int dispari = CercaDispari(vet, dim);

    printf("I numeri positivi sono %d \n i numeri nulli sono %d \n i numeri negativi sono %d \n",positivi,nulli,negativi);
    printf("In numeri pari sono %d, quelli dispari sono %d \n" ,pari,dispari);

    int crescente = Crescente(vet, dim );
    int decrescente = Decrescente(vet, dim);

    if( crescente == 1 && decrescente == 0 )
    {
        printf("La sequenza e' in ordine crescente \n");
    }
    else if( crescente == 0 && decrescente == 1 )
    {
        printf("La sequenza e' in ordine decrescente \n");
    }
    else
    {
        printf("La sequenza non e' ne' crescente ne decrescente \n");
    }

}
