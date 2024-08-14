/* ------------------------------------------------------------
                AlgoSdec - test de programmes
                Mini jeu du pendu - main pour tester
		F. Balmas		Jan 2022
   ------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <assert.h>

int existe (char lettre, char *mot, char *trouve);

char mot[9];
char trouve[9];


// extern char trouve[9];

int existe ( char lettre, char *mot, char *trouve ) {
  int pos;
  int bonl;

  bonl = 0;
  // ligne ou il y a l'erreur
  for (pos=0 ; pos < 7 && mot[pos] != '\0' ; pos++) {
  // ligne corrigee
  // for (pos=0 ; pos <= 7 && mot[pos] != '\0'; pos++) {
      if (mot[pos] == lettre) {
          bonl += 1;
	      trouve[pos] = lettre;
	  }
    }
  return bonl;
}

int initialise (char *mot, char *trouve) {
	int pos, nbl;

	for(pos=0; pos<=7 && mot[pos]!='\0' ; pos++) {
		trouve[pos]='-';
	}
	nbl=pos;
	for (  ; pos<=7 ; pos++) {
		trouve[pos]='*';
	}
	trouve[pos]='\0';

	return nbl;
}

int encore_a_trouver(char *trouve) {
    int pos, cpt;
    for (pos=0, cpt=0 ; pos <=7 ; pos++) {
        if (trouve[pos] == '-') {
            cpt++;
        }
    }
    return cpt;
}

void affiche(char *trouve) {
	int pos;

	for (pos=0 ; pos<=7 && trouve[pos]!='*' ; pos++) {
		printf("%c ", trouve[pos]);
	}
	printf("\n");
}

int main (void) {
  int res;

  /* creation de la configuration pour test, avec un mot de taille moyenne */
  printf("Tests avec un mot de taille moyenne : ");
  strcpy ( mot, "classe" );
  printf("%s\n", mot);
  printf ("Debut des tests\n");
  res = existe('m',mot,trouve);
  printf ("la valeur est: %d, \n",res);
  assert(res == 0);

  res = existe('a',mot,trouve);
  printf ("la valeur est: %d, \n",res);

  assert(res == 1);

  res = existe('s',mot,trouve);
  printf ("la valeur est: %d, \n",res);
  
  assert(res == 2);

  res = existe('c',mot,trouve);
  printf ("la valeur est: %d, \n",res);
  
  assert(res == 1);

  res = existe('e',mot,trouve);
  printf ("la valeur est: %d, \n",res);
  
  assert(res == 1);

  res = existe('p',mot,trouve);
  printf ("la valeur est: %d, \n",res);
  assert(res == 0);


  printf ("Tout est OK\n\n");


  /* creation de la configuration pour test, avec un mot le plus long */
  printf("Tests avec un mot le plus long possible : ");
  strcpy ( mot, "cartable" );
  printf("%s\n", mot);
  printf ("Debut des tests\n");

  res = existe('m',mot,trouve);
  printf ("la valeur est: %d, \n",res);
  assert(res == 0);


  printf ("Tout est OK\n\n");

  /* creation de la configuration pour test, avec un mot le plus court */
  printf("Tests avec un mot tres court : ");
  strcpy ( mot, "de" );
  printf("%s\n", mot);
  printf ("Debut des tests\n");

  res = existe('m',mot,trouve);
  printf ("la valeur est: %d, \n",res);
  assert(res == 0);


  printf ("Tout est OK\n\n");

  printf ("Fin des tests\n");

  return (EXIT_SUCCESS);
}
