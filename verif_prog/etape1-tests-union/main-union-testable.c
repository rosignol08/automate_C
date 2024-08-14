/* -------------------------------------------------------------
Union de 2 ensembles
Version de XY reorganisee pour etre testable
Fichier principal (main)

Cours F. Balmas                            2024
-------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "liste.h"
#include "hashcode.h"

#define NB 10

int getpid();
int add_nom_si_necessaire(char *);

int main()
{
    int res;
    char liste_mots[NB][10]={ "tir", "car", "bar", "mur", "cor", "pur", "mer", "sel", "mal", "vue" };
    char liste_mots2[NB][10]={ "bord", "cale", "mur", "sel", "bleu", "vert", "car", "mer", "gris", "vue" };
    int compteur = 0;
    init_freeliste();
    init_tabhash();
    //print_tabhash();

    int cmp = 0;
    for(int i = 0 ; i< NB ; i++)
    {
        //printf("%s ajoute dans l'union\n", liste_mots[i]);
        add_nom(liste_mots[i]);
        cmp++;
    }
    //print_tabhash();

    int nbr_elemnt_union = 0;
    for(int i = 0;i<NB;i++)
    {
        res = add_nom_si_necessaire(liste_mots2[i]);
        if (res == 1)
        compteur++;
    }
    nbr_elemnt_union = compteur + cmp;

    //print_tabhash();

    printf("==> soit %d elt\n",compteur);
    printf("nombre element ensemble 1 : %d\nnombre element ensemble 2 : %d\nnombres elements dans l'union %d\n",NB,NB,nbr_elemnt_union);

    return EXIT_SUCCESS;
}
