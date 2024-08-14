/* -------------------------------------------------------------
   Demo hashcoding

   F. Balmas                                 2022
   -------------------------------------------------------------

#include "freel-liste.h"
#include "hashcode.h"
#include <stdio.h>
#include <stdlib.h>

char *table_mots[] = {"vigne",    "calculer", "chemin",   "route",
                      "cartable", "crayon",   "mine",     "coussin",
                      "pelochon", "cahier",   "classeur", ""};

int main() {
  int i, sortie;
  char mot[21];
  char action;
  LINKED res;

  init_freeliste();
  init_tabhash();

  for (i = 0; table_mots[i] != ""; i++) {
    printf("ajout de %s\n", table_mots[i]);
    add_nom(table_mots[i]);
  }
  print_tabhash();
  printf("%d elts ajoutes\n", i);
  printf("entrez votre mot\n");
  scanf("%s", mot);
  res = search_nom(mot);
  if (res == NULL) {
    printf("ce mots n'est pas disponible");
  } else {
    printf("ce mot est dans la liste");
  }
  // a coder :
  // boucle interactive permettant de chercher si un mot est dans
  // la table_hash, avec search_nom(char *)
  // d'ajouter d'autres mots, avec add_nom(char *)
  // d'afficher la table_hash, avec print_tabhash()
  // ou de quitter
  return 1;
}

*/
/* -------------------------------------------------------------
Intersection avec hashcoding

F. Balmas                                 2024
-------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "freel-liste.h"
#include "hashcode.h"
#include "list.c"

// importation de base et liste
//#include "donnees-mots.c"
// petites base et liste pour tester

struct linked LINTER;
LINKED TI;

int main(void) {
  // initialisation de la freeliste (pour les listes)
  init_freeliste();
  // initialisation de la table de hash
  init_tabhash();
  // initialisation de la liste de resultats
  TI = &LINTER;
  init_list(TI);
  // le code pour determiner le nb d'elts dans l'intersection en UTILISANT le HASHCODE
  // + le code pour memoriser ces elements dans une liste
  init_tabhash();
  
  int nbb, nbl;
  nbb = 0;
  nbl = 0;
  //for (int i = 0; base[i] != ""; i++) {
  //}
  for (int i = 0; base[i] != ""; i++) {
    //printf("ajout de %s\n", base[i]);
    add_nom(base[i]);
    nbb += 1;
  }

  for (int i = 0; liste[i] != ""; i++) {
    nbl += 1;
  }
  int cptelt, cptdouble = 0;
  //nbb = 10; //5263
  //nbl = ; //857
  char mot[21];
  LINKED res;
  for (int i = 0; liste[i] != "" ; i++) {
    strcpy(mot, liste[i]);
    res = search_nom(mot);
    if (res == NULL) {
      //printf("ce mot n'est pas disponible\n");
    } else {
      //printf("ce mot est dans la liste\n");
      cptdouble += 1;
    }
  }
  cptelt = (nbb + nbl) - cptdouble;
  // affichage des resultats
  printf("%d dans base et %d dans liste : %d elt differents au total, %d doublons trouves\n", nbb, nbl, cptelt, cptdouble);

  //printf("longueur liste intersection : %d\n", nb);
  print_list(TI);
  return 0;
}