/*
 * main.c
 *
 *  Created on: 10 dic 2019
 *      Author: simone
 */
#include <stdio.h>
#include <stdlib.h>

// funzione per stamapre la sequenza di caratteri secondo la frequenza desiderata
void StampaNcarattteri( FILE* file_caratteri, int frequenza );

// funzione per contare il numero di presenza di un carattere tra quelli stampati
int ContaCarattereSelezionato( FILE* file_caratteri, int frequenza, char carattere_selezionato );

int main()
{

    FILE* file_read;

    file_read = fopen("file.txt","r");

    if( file_read == NULL )
    {
        printf("ERRORE: file non aperto! \n");
    }
    else
    {

        int frequenza_caratteri_stampa;
        char seleziona_carattere;

        printf("Inserisci la frequenza di caratteri da stampare nel file \n");
            scanf("%d" ,&frequenza_caratteri_stampa);

        StampaNcarattteri(file_read, frequenza_caratteri_stampa);

        // riporto testina all'inizio del file
        rewind(file_read);

        // svuoto buffer di input
        fflush(stdin);

        printf("\nInserisci il carattere di cui vuoi contare la frequenza tra i caratteri stampati \n");
            scanf("%c" ,&seleziona_carattere);
        
        int num_caratteri = ContaCarattereSelezionato( file_read, frequenza_caratteri_stampa, seleziona_carattere );

        printf("La frequenza del carattere selezionato tra quelli stampati e' %d \n" ,num_caratteri);

    }

        system("pause");
    return 0;
}


void StampaNcarattteri( FILE* file_caratteri, int frequenza )
{
    int count = 1;

    if( frequenza > 0 )
    {
        
        while( !feof(file_caratteri) )
        {

            char carattere_file = fgetc(file_caratteri);

            if( count % frequenza == 0 )
            {
                printf(" %c " ,carattere_file);
            }

            count = count + 1;
        }
    }
}

int ContaCarattereSelezionato( FILE* file_caratteri, int frequenza, char carattere_selezionato )
{

    int count = 1;
    int count_caratteri = 0;

    if( frequenza > 0 )
    {
        while( !feof(file_caratteri) )
        {

            char carattere_file = fgetc(file_caratteri);

            if( count % frequenza == 0 && carattere_file == carattere_selezionato )
            {
                count_caratteri = count_caratteri + 1;
            }

            count = count + 1;
        }
    }

    return count_caratteri;
}


