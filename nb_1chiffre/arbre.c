/* ------------------------------------------------

   Arbres binaires : fonctions standard

   F. Balmas, mars 2021

   ------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

TREE cree_arbre (char x)
{
TREE p;

p = (TREE) malloc(sizeof(struct arbre));
if (p == NULL)
  {
    perror("Plus de memoire\n");
    exit(1);
  }
p->val = x;
p->G = NULL;
p->D = NULL;
}

void affiche_pre(TREE a)
{
if (a != NULL)
  {
    printf ("%c ", a->val);
    affiche_pre(a->G);
    affiche_pre(a->D);
  }
}

void affiche_in(TREE a)
{
if (a != NULL)
  {
    affiche_in(a->G);
    printf ("%c ", a->val);
    affiche_in(a->D);
  }
}

void affiche_post(TREE a)
{
if (a != NULL)
  {
    affiche_post(a->G);
    affiche_post(a->D);
    printf ("%c ", a->val);
  }
}



