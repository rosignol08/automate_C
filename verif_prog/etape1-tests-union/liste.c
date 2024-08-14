/*  Ce fichier contient les definitions necessaires pour
    l'implementation de la librairie list

    F. Balmas 2021

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "liste.h"


#define NL 200
#define NODEBUG



static LINKED remove_begin(LINKED t);
static void remplir_freeliste(void);

static struct linked TETE;
static LINKED T;

static LINKED remove_begin(LINKED t) {
  LINKED p;
  p=t->cell;
  t->cell = (t->cell)->cell;
  return p;
}

static void remplir_freeliste(void) {
LINKED m, pm, pf;
#ifdef DEBUG
fprintf (stderr,"Remplissage de la freeliste ...\n");
#endif
 m = (LINKED) malloc(NL * sizeof(struct linked));
 if (m == NULL) {
   fprintf (stderr, "Plus de memoire disponible ...\n");
   exit(1);
 }
 pf = T;
 for (pm=m; pm<m+NL ; pm++) {
   pf->cell = pm;
   pf = pf->cell;
 }
 pf->cell = NULL;
#ifdef DEBUG
printf ("Length TETE : %d\n", length(T));
#endif
}


void init_list (LINKED l) {
	l->cell = NULL;
}


LINKED alloc_list(void) {
LINKED p;

 if (T->cell == NULL)
   remplir_freeliste();
// il y a au moins un chainon de disponible dans la liste des free
 p = remove_begin(T);
 init_list(p);
 return p;
}

void add_begin (LINKED t, LINKED l) {
	l->cell = t->cell;
	t->cell = l;
}

void print_list (LINKED l) {
LINKED p;

	for (p=l->cell ; p!= NULL ; p=p->cell)
	    print_nom(p);
	printf ("\n");
}
void print_list_compact (LINKED l) {
LINKED p;

	for (p=l->cell ; p!= NULL ; p=p->cell)
	    print_nom(p);
	//printf ("\n");
}

void print_nom(LINKED contact) {
  printf ("%s, ", contact->nom);
}


LINKED member (char *x, LINKED l) {
	LINKED p;

	for (p = l->cell; p != NULL; p = p->cell) {
	   if (strcmp(p->nom, x) == 0)
		return p;
	}
	return NULL;
}

void init_freeliste(void) {
T = &TETE;
}

int length(LINKED l) {
LINKED p;
int n=0;
 for (p=l->cell ; p!=NULL ; p=p->cell)
   n++;
 return n;
}

/*LINKED member (char *x, LINKED l) {
	LINKED p;

	for (p=l->cell ; p!=NULL ; p=p->cell) {
	   if ( strcmp(p->nom, x) != 0 )
		return (p);
	   }
	return ((LINKED) 0);
}
*/