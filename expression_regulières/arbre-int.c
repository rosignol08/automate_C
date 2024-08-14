/* ------------------------------------------------

   Arbres binaires : fonctions standard

   F. Balmas, mars 2021

   ------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include "arbre-int.h"

TREE cree_arbre (int x)
{
TREE p;

p = (TREE) malloc(sizeof(struct arbre));
if (p == NULL)
  {
    perror("Plus de memoire\n");
    exit(1);
  }
VALUE(p) = x;
LEFT(p) = NULL;
RIGHT(p) = NULL;
return p;
}

void affiche_pre(TREE a)
{
if (a != NULL)
  {
    printf ("%d ", VALUE(a));
    affiche_pre(LEFT(a));
    affiche_pre(RIGHT(a));
  }
}

void affiche_in(TREE a)
{
if (a != NULL)
  {
    affiche_in(LEFT(a));
    printf ("%d ", VALUE(a));
    affiche_in(RIGHT(a));
  }
}

void affiche_post(TREE a)
{
if (a != NULL)
  {
    affiche_post(LEFT(a));
    affiche_post(RIGHT(a));
    printf ("%d ", VALUE(a));
  }
}
