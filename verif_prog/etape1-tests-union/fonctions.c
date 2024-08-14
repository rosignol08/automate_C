/* -------------------------------------------------------------
Union de 2 ensembles
Version de XY reorganisee pour etre testable
Fichier de fonctions (a part pour pouvoir etre utilise dans les tests)

Cours F. Balmas                            2024
-------------------------------------------------------------
*/
#include <stdlib.h>
#include <stdio.h>
#include "liste.h"
#include "hashcode.h"

int add_nom_si_necessaire(char *mot) {

    if(search_nom(mot) != NULL ){
        //printf("%s ajoute dans l'union\n", mot);
        add_nom(mot);
        return (1);
    }
    return (0);
}

// REM remplacer != qui n'est pas logique par == qui est logique
// modifie le pb mais ne le resoud pas
