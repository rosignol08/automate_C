/* -------------------------------------------------------------
Union de 2 ensembles
Version de XY reorganisee pour etre testable
Verification par affichage / assert

F. Balmas                                 2024
-------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "liste.h"
#include "hashcode.h"

#define NB 10

int add_nom_si_necessaire(char *mot);
void verif_add_nom_si_necessaire();
void verif_search_nom();
void verif_member();
char liste_mots[NB][30]={ "tir", "car", "bar", "mur", "cor", "pur", "mer", "sel", "mal", "vue" };
char liste_mots2[NB][30]={ "bord", "cale", "mur", "sel", "bleu", "vert", "car", "mer", "gris", "vue" };

int main() {
    int i, res;
    char buff[30];

    init_freeliste();
    init_tabhash();

    printf("ajout des elts de liste_mots\n");
    for(i = 0 ; i< NB ; i++) {
        add_nom(liste_mots[i]);
    }
    print_tabhash();
    printf("\n");
    printf("TESTS verif_search_nom :\n");
    verif_search_nom();
    printf("FIN TESTS verif_search_nom :\n");
    printf("\n");
    printf("TESTS fn member() :\n");
    verif_member();
    printf("FIN tests fn member()\n");
    printf("\n");
    printf("TESTS fn add_nom_si_necessaire() :\n");
    verif_add_nom_si_necessaire();
    print_tabhash();
    printf("FIN tests fn add_nom_si_necessaire()\n");
    printf("OK fin des tests\n");
}

void verif_add_nom_si_necessaire() {
    int res;

    //printf("des mots qui doivent etre ajoutes\n");
    printf("cale  (doit etre ajoute)\n");
    res = add_nom_si_necessaire("cale");
    assert(res == 1);

    printf("auto  (doit etre ajoute)\n");
    res = add_nom_si_necessaire("auto");
    assert(res == 1);

    printf("bord  (doit etre ajoute)\n");
    res = add_nom_si_necessaire("bord");
    assert(res == 1);

    //printf("des mots qui ne doivent pas etre ajoutes\n");
    printf("pur  (ne doit pas etre ajoute)\n");
    res = add_nom_si_necessaire("pur");
    assert(res == 0);

    printf("sel  (ne doit pas etre ajoute)\n");
    res = add_nom_si_necessaire("sel");
    assert(res == 0);

    printf("bar  (ne doit pas etre ajoute)\n");
    res = add_nom_si_necessaire("bar");
    assert(res == 0);
}



void verif_search_nom() {
    LINKED res;

    //printf("des mots qui ne doivent pas etre trouves\n");
    printf("cale  (ne doit pas etre trouve)\n");
    res = search_nom("cale");
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res == NULL);

    printf("auto  (ne doit pas etre trouve)\n");
    res = search_nom("auto");
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res == NULL);

    printf("bord  (ne doit pas etre trouve)\n");
    res = search_nom("bord");
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res == NULL);

    //printf("des mots qui doivent etre trouves\n");
    printf("pur  (doit etre trouve)\n");
    res = search_nom("pur");
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res != NULL);

    printf("sel  (doit etre trouve)\n");
    res = search_nom("sel");
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res != NULL);

    printf("bar  (doit etre trouve)\n");
    res = search_nom("bar");
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res != NULL);
}

void verif_member() {
    LINKED res, T;
    struct linked TETE;
    int i;

    // creation d'une liste pour les tests
    T = &TETE;
    init_list(T);

    printf("tests avec liste vide : ");
    print_list(T);

    printf("cale (inexistant)\n");
    res = member("cale", T);
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res == NULL);

    // tests avec une liste a un seul element
    res = alloc_list();
    strcpy(res->nom, liste_mots[0]);
    add_begin(T, res);

    printf("tests avec liste a un seul element : ");
    print_list(T);

    printf("tir (existant)\n");
    res = member("tir", T);
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res != NULL);

    // A completer en se basant sur le pdf 
    // code les tests pour les mots suivants

    printf("sel (inexistant)\n");
    res = member("sel", T);
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res != NULL);

    // tests avec une liste a plus d'elements
    // ajouter a T les mots de liste_mots[] (sizeof(liste_mots)/sizeof(char)) -1
    T->cell->cell=NULL;
    for (i=0 ; i < NB ; i++) {
        res = alloc_list();
        strcpy(res->nom, liste_mots[i]);
        add_begin(T, res);
    }
    
    printf("tests avec une liste a plusieurs elements : ");
    print_list(T);

    printf("pur  (existant en milieu de liste)\n");
    res = member("pur", T);
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res != NULL);

    printf("vue  (existant en debut de liste)\n");
    res = member("vue", T);
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res != NULL);

    printf("tir  (existant en fin de liste)\n");
    res = member("tir", T);
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res != NULL);

    printf("cale  (inexistant)\n");
    res = member("cale", T);
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res != NULL);

    // tests dans une liste contenant uniquement plusieurs fois le meme mot
    T->cell->cell=NULL;
    for (i=0 ; i<5 ; i++) {
        res = alloc_list();
        strcpy(res->nom, "vue");
        add_begin(T, res);
    }

    printf("tests dans une liste contenant uniquement plusieurs fois le meme mot > ");
    print_list(T);

    printf("mer  (inexistant)\n");
    res = member("mer", T);
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res != NULL);

    printf("vue  (existant)\n");
    res = member("vue", T);
    if (res==NULL)
        printf("non trouve\n");
    else
        printf("trouve\n");
    assert(res != NULL);
}