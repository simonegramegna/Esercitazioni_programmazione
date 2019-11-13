/*
 * main.c
 *
 *  Author: Gramegna Simone
 *
 */

#include <stdio.h>
#include <stdlib.h>

//dimensione predefinita del vettore
#define N 20

void LeggiVettore( int vet[], int dim );

int CalcolaFrequenza(int vet[], int dim, int numero);

int FrequenzaMassima( int vet[], int dim );

int FrequenzaMinima( int vet[], int dim );


int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);



    int numeri[N];

    //richiamo funzione leggi vettore
    LeggiVettore( numeri, N );


    int Fmassima = FrequenzaMassima(numeri, N);
    int Fminima = FrequenzaMinima(numeri, N);

    // stampa valori
    printf("Il valore con frequenza massima e' %d \nIl valore con frequenza minima e' %d" ,Fmassima,Fminima);


        system("pause");

    return 0;
}

void LeggiVettore( int vet[], int dim )
{
    int i = 0;

    while( i < dim )
    {

        //inserisco valori interi nel vettore
        printf("Inserisci un valore intero \n");
            scanf("%d" ,&vet[i]);

        i = i + 1;
    }

}

int CalcolaFrequenza(int vet[], int dim, int numero)
{

    int i = 0;
    int frequenza = 0;

    while( i < dim )
    {

        if( vet[i] == numero )
        {
         /*incremento di uno la frequenza se il valore nel vettore e'
            uguale al valore selezionato
        */
            frequenza = frequenza + 1;
        }

        i = i + 1;
    }

    return frequenza;

}


int FrequenzaMassima( int vet[], int dim )
{
    int i = 0;
    int fmax = 0;
    int fmax_e;
    int frequenza_valore;
    int valore;

    while( i < dim )
    {
        valore = vet[i];
        frequenza_valore = CalcolaFrequenza( vet, dim, valore );

        if( frequenza_valore > fmax )
        {
            fmax = frequenza_valore;
            fmax_e = valore;

        }

        i = i + 1;

    }

    return fmax_e;
}

int FrequenzaMinima( int vet[], int dim )
{
    int i = 1;
    int fmin;
    int fmin_e;
    int frequenza;
    int valore;

    // assegno come valore iniziale di fmin la frequenza del primo elemento
    valore = vet[0];
    fmin = CalcolaFrequenza( vet, dim, valore );
    fmin_e = valore;

    while( i < dim )
    {

        // calcolo la frequenza degli elementi restanti nel vettore
        valore = vet[i];
        frequenza = CalcolaFrequenza( vet, dim, valore );

        if( frequenza < fmin )
        {

            fmin = frequenza;
            fmin_e = valore;

        }

        i = i + 1;

    }

    return fmin_e;
}

