/* ---------------------------------------------------------------

   Tests automates et tables de transitions

   F. Balmas   mars 2022

   ---------------------------------------------------------------
*/

#include <stdio.h>

// taille max du buffer de saisie
#define MAX 20

// les types possibles
enum types { ZERO, UN };



#define NBETATS 2
#define NBTYPES 2
#define ETATENTREE 'A'
#define ETATSORTIE 'B'
#define ETATERREUR 'A'


#define T1

#ifdef T1
// accepte nombre impair ecrit en binaire
int ttransit [NBETATS][NBTYPES] = {
			{ 'A', 'B' } ,
			{ 'A', 'B' } };
#endif

#ifdef T2
// accepte nb pair
#endif

#ifdef T3
// nb pair de zero
#endif



void affiche_ttransit(int (*)[NBTYPES]);
enum types get_type(char);
void print_typ(char *);
char automate(char *, char);


void main(void) {
char etat;
char str[MAX];

	affiche_ttransit(ttransit);
	while (1) {
		printf("> ");
		scanf("%s", str);
		etat = automate(str, ETATENTREE);
		if (etat==ETATSORTIE ) {
			printf("etat final %c --> accepte\n\n", etat);
		} else {
			printf("etat final %c --> rejete\n\n", etat);
		}
	}
}

// appliquer la moulinette sur la string
char automate(char *str, char etat) {
int i;
enum types t;
	for (i=0 ; str[i]!='\0' ; i++) {
		printf("\"%s\"    %c /%c/", str, etat, str[i]);
		t = get_type(str[i]);
		etat = ttransit[etat-'A'][t];
		printf("  -->  %c\n", etat);
	}
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
	if (l == '0') return ZERO;
	return UN;
}

//  ZERO, CHIFFRE, POINT, SIGNE, SEP, LETTRE, AUTRE
void affiche_ttransit(int tab[NBETATS][NBTYPES]) {
int i, j;
	printf("ETAT | ZER |  UN |    Sortie %c = accepte  %c = refuse\n", ETATSORTIE, ETATERREUR);
	for (i=0 ; i<NBETATS ; i++) {
		printf("  %2c |  ", 'A'+i);
		for (j=0 ; j<NBTYPES ; j++) {
			printf("%2c |  ", tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


/* ---------------------------------------------------
     traces d'execution

	 ETAT | ZER |  UN |    Sortie B = accepte  A = refuse
   		A |   A |   B |
   		B |   A |   B |

   > 101
   "101"    A /1/  -->  B
   "101"    B /0/  -->  A
   "101"    A /1/  -->  B
   etat final B --> accepte

   > 1100
   "1100"    A /1/  -->  B
   "1100"    B /1/  -->  B
   "1100"    B /0/  -->  A
   "1100"    A /0/  -->  A
   etat final A --> rejete

   > 0011
   "0011"    A /0/  -->  A
   "0011"    A /0/  -->  A
   "0011"    A /1/  -->  B
   "0011"    B /1/  -->  B
   etat final B --> accepte

   > 1001
   "1001"    A /1/  -->  B
   "1001"    B /0/  -->  A
   "1001"    A /0/  -->  A
   "1001"    A /1/  -->  B
   etat final B --> accepte

   > 1010
   "1010"    A /1/  -->  B
   "1010"    B /0/  -->  A
   "1010"    A /1/  -->  B
   "1010"    B /0/  -->  A
   etat final A --> rejete
*/