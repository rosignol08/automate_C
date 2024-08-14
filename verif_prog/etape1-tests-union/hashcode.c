/* ***************************************************************
*
*  Hashcoding
*
*  F. Balmas 2021
*
******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"
#include "hashcode.h"

#define NODEBUG
#define SIZE BUFSIZ

LINKED tabhash[N];

// 23 elt dans tabhash N=23
// 100 mots à ranger dans tabhash
// 4 mot dans chaque entree de tabhash


// compteur du nb de boucles
long nbbi;

 int compute_hash(char *word);

void init_tabhash(void) {
int i;

        for (i=0 ; i<N ; i++)
        {
           tabhash[i] = alloc_list();;
           init_list (tabhash[i]);
        }
}

int compute_hash (char *word) {
int i, nb;

        nb = 0;
        for (i=0 ; word[i] != '\0' ; i++)
           nb += word[i];
        return (nb % N);
}

LINKED search_nom (char *nom) {
int hash;

	hash = compute_hash (nom);
	// printf("hash:%s %d \n ", nom, hash);
	return (member(nom, tabhash[hash]));
}

void add_nom(char *nom) {
int hash;
LINKED new;

    printf("ajout de %s\n", nom);
	hash = compute_hash (nom);
	new = alloc_list();
	strcpy(new->nom, nom);
	add_begin (tabhash[hash], new);
}

void print_tabhash(void) {
int i, j;
	printf("tabhash> \n");
	for(i=0 ; i<N ; i++) {
        //printf("\n%d : ", i);
        printf("%d : ", i);
		print_list(tabhash[i]);
	}
}
void print_tabhash_compact(void) {
int i, j;
	printf("print tabhash\n");
	for(i=0 ; i<N ; i++) {
		printf("%d : ", i);
		print_list(tabhash[i]);
	}
}
