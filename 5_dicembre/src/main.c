/*
 * main.c
 *
 *  Created on: 5 dic 2019
 *      Author: simone
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

// funzione per allocare vettore di stringhe
char** AllocaVetStringhe( char** vetstr, int dim );

// funzione per allocare una stringa
char* AllocaStringa( char* s1, int dim );

// funzione per prendere in input una stringa
char* InputString( char* source, char* dest );

// funzione per prendere in input il vettore si stringhe
void InputVS( char** vs, int dim );

// funzione per stampare il vettore di stringhe
void StampaVS( char** vs, int dim );

// funzione per cercare una stringa in input
int CercaStringa(char** vetstr, int dim, char* search);

// funzione per stampare i risultati ottenuti dalla ricerca
void StampaRisultati( int res );

// funzione menù
void InsertSearch( char* name_search );

int main()
{

    int dimvet;
    char** vetstr;

    printf("Inserisci la dimensione del vettore di stringhe \n");
        scanf("%d" ,&dimvet);

    printf("\n\n");

        // alloco il vettore di stringhe
        vetstr = AllocaVetStringhe(vetstr,dimvet);

        // prendo in input il vettore di stringhe
        InputVS(vetstr,dimvet);

    printf("\n\n");

    char* s1 = AllocaStringa(s1,MAX);
    char* s2;

    printf("Inserisci una stringa da cercare nel vettore di stringhe \n");
        scanf("%s" ,s1);

        s2 = InputString(s1,s2);

    int r1 = CercaStringa(vetstr,dimvet,s2);

    	// stampo i risultati della ricerca
        StampaRisultati(r1);

        system("pause");
return 0;
}

char** AllocaVetStringhe( char** vetstr, int dim )
{
    vetstr = (char**) calloc(dim,sizeof(char*));

    return vetstr;
}

char* InputString( char* source, char* dest )
{

    int dim_source = strlen(source);

    // nel caso in cui la stringa inserista sia più grande della dimensione massima
    if( dim_source > MAX )
    {
        source = realloc(source, dim_source*sizeof(char) );
    }

    // alloco la stringa di destinazione
    dest = AllocaStringa(dest,dim_source);

    strcpy(dest,source);

    return dest;
}

char* AllocaStringa( char* s1, int dim )
{
    s1 = (char*) calloc( dim+1, sizeof(char) );

    return s1;
}

void InputVS( char** vs, int dim )
{
    int i = 0;

    while( i < dim )
    {

        // alloco dinamicamente la stringa temporanea
        char* temp;

        temp = AllocaStringa(temp,MAX);

        printf("Inserisci una stringa \n ");
            scanf("%s" ,temp);

           *(vs + i) = InputString(temp,*(vs+i));

        free(temp);

        i++;
    }
}

void StampaVS( char** vs, int dim )
{
    int i = 0;

    while( i < dim )
    {

        printf("%s\n" ,*(vs + i) );

        i = i + 1;
    }
}

int CercaStringa(char** vetstr, int dim, char* search)
{

    int found = -1;
    int i = 0;

    while(i < dim && found == -1)
    {
        int compare = strcmp(*(vetstr + i), search );

        if( compare == 0 )
        {
            found = i;
        }

        i = i + 1;
    }

    return found;
}

void StampaRisultati( int res )
{
    if( res == -1 )
    {
        printf("Il nome cercato non e' presente nel vettore \n");
    }
    else
    {
        printf("Il nome cercato e' presente nella posizione %d \n" ,res);
    }

}


