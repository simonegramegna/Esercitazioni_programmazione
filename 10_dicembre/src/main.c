/*
 * main.c
 *
 *  Created on: 10 dic 2019
 *      Author: simone
 */
#include <stdio.h>
#include <stdlib.h>

/ Funzione per stampare un carattere ogni 'num' nel file
void StampaUnoN(FILE* fp, int num);

// funzione per contare quante volte compare il carattere selezionato nel file ogni num cratteri stampati
int NumCarattere(FILE* fp, int num, char c_selected);

int main()
{

    FILE* f_read;

    f_read = fopen("file.txt","r");

    if(f_read == NULL)
    {
        printf("Errore: file non aperto \n");
    }

    int num;
    char choose;

    printf("Inserisci la frequenza di caratteri da stampare \n");
        scanf("%d" ,&num);

        // svuoto il buffer di input
        fflush(stdin);

    printf("\nInserisci il carattere da contare tra i caratteri stampati dal file\n");
        scanf("%c" ,&choose);

        StampaUnoN(f_read,num);

        // riporto la testina all'inizio del file
        rewind(f_read);

        int num_caratteri = NumCarattere(f_read,num,choose);

        printf("Il carattere %c e' presente %d volte tra i caratteri stampati \n" ,choose,num);
        
        system("pause");
    return 0;
}

void StampaUnoN(FILE* fp, int num)
{
    
    int i = 1;

    while( !feof(fp) )
    {
        
        char c_print = fgetc(fp);

        if( i % num == 0)
        {
            printf(" %c ",c_print);
        }
        
        i =  i + 1;
    }
}

int NumCarattere(FILE* fp, int num, char c_selected)
{
    int i = 1;
    int count_char = 0;

    while( !feof(fp) )
    {

        char c_conf = fgetc(fp);

        if( (i % num == 0 ) && (c_conf == c_selected))
        {
            count_char = count_char + 1;
        }

        i = i + 1;
    }

    return count_char;
}

