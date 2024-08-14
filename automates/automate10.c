/* ---------------------------------------------------------------

   Expressions mathematiques
   Reconnaissance de nb entiers positifs ne commencant pas par 0
   avec automate et table de transition

   F. Balmas   mars 2022

   ---------------------------------------------------------------
*/

#include <stdio.h>

// taille max du buffer de saisie
#define MAX 20

// les types possibles 
enum types { ZERO, CHIFFRE, POINT, SIGNE, SEP, LETTRE, AUTRE };


// definition de l'automate
//#define NBETATS 4
//#define NBTYPES 7
//#define ETATENTREE 0
//#define ETATSORTIE 10
//#define ETATERREUR -1
//int ttransit [NBETATS][NBTYPES] = {
//	/*etats*/{ -1, 1, -1, 1, -1, -1, -1 },
//	/*type entre*/{ 1, 1, -1, -1, 10, -1, -1 }};
//rejette les + et -
//int ttransit [NBETATS][NBTYPES] = {
//	/*etats*/	  { -1, 1, 1, 2, -1, -1, -1 },
//	/*type entre*/{ 1, 1, 10, 2, 10, -1, -1 },
//				  { -1, 1, -1, -1, -1, -1, -1 }};
// definition de l'automate
#define NBETATS 5
#define NBTYPES 7
#define ETATENTREE 0
#define ETATSORTIE 10
#define ETATERREUR -1
//rejette les booleen de type 1.1.1
int ttransit [NBETATS][NBTYPES] = {
	/*etats*/	  { 1, 1, 2, 4, -1, -1, -1 },
	/*type entre*/{ 1, 1, 3, -1, 10, -1, -1 },
				  { 3, 3, -1, -1, -1, -1, -1 },
				  { 3, 3, -1, -1, 10, -1, -1 },
				  { 1, 1, 2, -1, -1, -1, -1 }
};

void affiche_ttransit(int (*)[NBTYPES]);
enum types get_type(char);
void print_typ(char *);
int automate(char *, int);


void main(void) {
	int etat;
	char str[MAX];
	affiche_ttransit(ttransit);
	while (1) {
		printf("> ");
		scanf("%s", str);
		etat = automate(str, ETATENTREE);
		if (etat==ETATSORTIE ) {
			printf("= accepte\n");
		} else {
			printf("= rejete\n");
		}
	}
}

// appliquer la moulinette sur la string 
int automate(char *str, int etat) {
int i;
enum types t;
	for (i=0 ; str[i]!='\0' ; i++) {
		t = get_type(str[i]);	
		etat = ttransit[etat][t];
		if (etat==ETATSORTIE || etat==ETATERREUR) {
			return etat;
		} 
	}
	// str[i] contient '\0', donc un SEP
	etat = ttransit[etat][SEP];
	return etat;
}

void print_typ (char *s) {
	int i;
	while (*s != '\0') {
		printf ("%c  %d\n", *s, get_type(*s));
		s++;
	}
}


enum types get_type (char l) {
	switch (l) {
		case '0': return ZERO; break;
		case '.': return POINT; break;
		case '+': return SIGNE; break;
		case '-': return SIGNE; break;
		case ' ': return SEP; break;
		case '\0': return SEP; break;
		case '\n': return SEP; break;
	}
	if (l >= '1' && l<='9') 
		return CHIFFRE;
	if (l>='a'&&l<='z' || l<='A'&&l<='Z')
		return LETTRE;
	// dans tous les autres cas
	return AUTRE;
}


//  ZERO, CHIFFRE, POINT, SIGNE, SEP, LETTRE, AUTRE 
void affiche_ttransit(int tab[NBETATS][NBTYPES]) {
	int i, j;
	printf("ETAT | ZER | CHI | POI | SIG | SEP | LET | AUT |\n");
	for (i=0 ; i<NBETATS ; i++) {
		printf("  %2d |  ", i);
		for (j=0 ; j<NBTYPES ; j++) {
			printf("%2d |  ", tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/* ---------------------------------------------------
     traces d'execution
ETAT | ZER | CHI | POI | SIG | SEP | LET | AUT |
   0 |  -1 |   1 |  -1 |  -1 |  -1 |  -1 |  -1 |
   1 |   1 |   1 |  -1 |  -1 |  10 |  -1 |  -1 |

> 23
= accepte
> 34.7
= rejete
> 025
= rejete
> +89
= rejete
> 45+
= rejete
> 45-
= rejete
> 123(
= accepte
> 45
= accepte
> 12ert
= rejete
> 12[
= rejete
>

*/