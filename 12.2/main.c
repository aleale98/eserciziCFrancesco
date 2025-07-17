/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOME 50
#define MAX_STUDENTI 5

// funzione per l'inserimento studenti


typedef struct _studente {
	char *nome;
	int eta;
} studente;


void inserisci_studenti(studente **studenti, int n) {
	for (int i = 0; i < n; i++) {
		studenti[i]=malloc(sizeof(studente));
		studenti[i]->nome = malloc(MAX_NOME*sizeof(char));
		printf("Inserisci il nome dello studente: \n");
		fgets(studenti[i]->nome, MAX_NOME, stdin);
		studenti[i]->nome[strcspn(studenti[i]->nome, "\n")] = '\0';  // Rimuove il carattere '\n' se presente

		printf("Inserisci eta:\n");
		scanf("%d", &studenti[i]->eta);
		// Consuma il '\n' lasciato da scanf nel buffer
		getchar();
	}
}

// funzione per l'ordinamento dell'array in ordine crescente con l'uso del bubble sort
void ordina_array(studente **studenti, int n) {
	for(int i=0; i < n-1; i++) {
		for(int j=0; j <n-1-i; j++) {
			if(studenti[j]->eta > studenti[j+1]->eta) {
				studente *tmp = studenti[j];
				studenti[j] = studenti[j+1];
				studenti[j+1] = tmp;

			}
		}
	}
}

// funzione per conatre e stampare gli studenti maggiorenni e minorenni
void conta_stampa(studente **studenti, int n) {
	int minorenni=0;
	int maggiorenni=0;

	for(int i=0; i < n; i++) {
		if(studenti[i]->eta>= 18) {
			maggiorenni++;
		} else {
			minorenni++;
		}
	}

	int i=0;
	printf("minorenni:\n");
	while(studenti[i]->eta < 18) {
		printf(" %s\n", studenti[i]->nome);
		i++;
	}
	printf("Totale minorenni: %d\n", minorenni);
	printf("maggiorenni:\n");
	while(i< MAX_STUDENTI) {
		printf(" %s\n", studenti[i]->nome);
		i++;
	}
	printf("Totale maggiorenni: %d\n", maggiorenni);
}

void dealloca_risorse(studente **studenti, int num_studenti) {
	for(int i = 0; i < MAX_STUDENTI; i++) {
		free(studenti[i]->nome);
		free(studenti[i]);
	}
	free(studenti);
}


int main()
{

	studente **studenti = malloc(MAX_STUDENTI*sizeof(studente));
	inserisci_studenti(studenti, MAX_STUDENTI);
	ordina_array(studenti, MAX_STUDENTI);
	conta_stampa(studenti, MAX_STUDENTI);
	dealloca_risorse(studenti, MAX_STUDENTI);

	return 0;
}

