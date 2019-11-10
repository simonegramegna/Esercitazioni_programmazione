/*
*   Esercitazione del 15 Ottobre 2019
*
*   Simone Gramegna
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 100 // definisco l'ipotetica dimensione del vettore
#define MIN_DIM 10 // definisco la dimensione minima del vettore
#define MIN_VALUE 18 // definisco il valore minimo in input ammesso nel vettore
#define MAX_VALUE 90 // definisco il valore massimo in input ammesso nel vettore
#define SENTINEL 0 // definisco un valore sentinella


// definisco la funzione per il calcolo della frequenza di un valore in un vettore
int CalcolareFrequenza( int vettore[], int num );

// definisco la funzione per la ricerca di un valore in un vettore
int CercaValore( int vettore[], int num );

// definisco la funzione per la ricerca del valore con frequenza massima all'interno del vettore
int MaxFreq( int vettore[] );

// definisco la funzione per la ricerca del valore con frequenza minima all'interno del vettore
int MinFreq( int vettore[] );


int main()
{

    struct
    {
        int frequenza;
        int Fmax;
        int Fmin;

    }risultati;

    int i;// contatore della prima iterazione
    int j;// contatore della seconda iterazione
    int valore;
    int duplicati;
    int numbers[DIM] = {0}; //assegno inizialmente valore 0 a tutti gli elementi del vettore

    printf("Inserire dei numeri interi compresi tra 18 e 90 \n");

    i = 0;

    do
    {

        printf("Inserisci un intero \n");
            scanf("%d" ,&valore);

            //controllo se il valore in input soddisfa le condizioni richieste
            if( ( valore >= MIN_VALUE ) && ( valore <= MAX_VALUE ) )
            {

                numbers[i] = valore;

                i = i + 1;

            }
            else
            {

                if( valore == 0 )
                {
                    printf("Sequenza di input terminata \n");
                }
                else
                {
                    printf("Valore non ammesso \n");

                }
            }

    } while ( ( valore != SENTINEL ) && ( i <= MIN_DIM ) );

    j = 0;

    while( numbers[j] != SENTINEL )
    {
        int numero_confronto = numbers[i];
        duplicati = CercaValore( numbers, numero_confronto );

        if( duplicati == 1 )
        {
            risultati.frequenza = CalcolareFrequenza( numbers, numero_confronto );

        }
        j = j + 1;
    }


    risultati.Fmax = MaxFreq( numbers );
    risultati.Fmin = MinFreq( numbers );

    printf("Il valore con frequenza massima nel vettore e' %d" ,risultati.Fmax);
    printf("Il valore con frequenza minima nel vettore e' %d" ,risultati.Fmin);

    system("pause");
return 0;
}

int CalcolareFrequenza( int vettore[], int num )
{

    int frequenza_valore = 0;
    int i = 0;

    while( vettore[i] != SENTINEL )
    {

        if( vettore[i] == num )
        {

            frequenza_valore = frequenza_valore + 1;

        }

        i = i + 1;

    }

    return frequenza_valore;

}

int CercaValore( int vettore[], int num )
{

    int i = 0;
    int numcounter = 0;

    while( vettore[i] != SENTINEL )
    {

        if( vettore[i] == num )
        {
            numcounter = numcounter + 1;
        }

        i = i + 1;
    }
    return numcounter;

}

int MaxFreq( int vettore[] )
{

   int valore_freqmax;
    int FreqMax = 0;
    int i = 0;


    while( vettore[i] != SENTINEL )
    {
        int valore;
        int FrequenzaValore;

        valore = vettore[i];
        FrequenzaValore = CalcolareFrequenza( vettore, valore );

        if( FrequenzaValore > FreqMax )
        {

            valore_freqmax = valore;
            FreqMax = FrequenzaValore;

        }

        i = i +1;
    }

    return valore_freqmax;
}


int MinFreq(  int vettore[] )
{

    int FrequenzaValore;
    int valore_freqmin;
    int valore;
    int FreqMin;

    int i = 1;

    //imposto come frequanza minima la frequenza del primo elemento
    FreqMin = CalcolareFrequenza(vettore, vettore[0]);

    while( vettore[i] != SENTINEL )
    {

        valore = vettore[i];
        FrequenzaValore = CalcolareFrequenza( vettore, valore);

        if( FrequenzaValore < FreqMin )
        {

           valore_freqmin = valore;
           FreqMin = FrequenzaValore;

        }

        i = i + 1;
    }

    return valore_freqmin;

}

