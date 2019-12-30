/*
 * esercizio2.c
 *
 * Author: Gramegna Simone
 *
 */
#include <stdio.h>
#include <stdlib.h>

// funzione per verificare la divisibilita' di dividendo per un divisore
int divisibile( int dividendo, int divisore );

// funzione per stampare il risultato ottenuto dalla funzione divisibile
void StampaDivisibile( int risultato, int divisore, int dividendo );

int main()
{
    int dividendo;
    int divisore;
    int divisibilita;

    printf("Inserisci il dividendo \n");
        scanf("%d" ,&dividendo);

    printf("Inserisci il divisore \n");
        scanf("%d" ,&divisore);

        // calcolo loa divisibilita'
        divisibilita = divisibile(dividendo, divisore);

        // stampo i risultati
        StampaDivisibile(divisibilita, divisore, dividendo);

        system("pause");
return 0;
}

int divisibile(int dividendo, int divisore)
{
    int divisibile = 0;
    int resto;

    resto = dividendo % divisore;

    if( resto == 0 )
    {
        divisibile = 1;
    }

    return divisibile;
}

void StampaDivisibile( int risultato, int divisore, int dividendo )
{
    if( risultato == 1 )
    {
        printf("Il dividendo %d e' divisibile per il divisore %d \n" ,dividendo ,divisore);
    }
    else if( risultato == 0 )
    {
        printf("Il dividendo %d non e' divisibile per il divisore %d \n" ,dividendo ,divisore);
    }
    else
    {
        printf("Errore!\n");
    }
    
}
