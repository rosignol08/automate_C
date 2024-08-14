/* ---------------------------------------------------------------

   Expressions mathematiques
   Reconnaissance de nb entiers non signes et signes
   avec automate et table de transition
   Version pour reconnaissance dans une chaine

   F. Balmas   mars 2021

   ---------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// les types possibles
enum types { CHIFFRE, POINT, SIGNE, SEP, LETTRE, AUTRE };



#define NBTYPES 6
#define ETATENTREE 0
#define ETATSORTIE 10
#define ETATERREUR -1

/*
// entier non signe dans une chaine
#define NBETATS 2
int ttransit [NBETATS][NBTYPES] = { { 1, -1, -1, -1, -1, -1 } ,
			    	    			{ 1, 10, 10, 10, 10, 10 } };

*/
/*
// entiers signes
#define NBETATS 3
int ttransit [NBETATS][NBTYPES] = { { 1, -1, 2, -1, -1, -1 } ,
						    	    { 1, 10, 10, 10, 10, 10 } ,
								    { 1, -1, -1, -1, -1, -1 } };
*/
//float signes
#define NBETATS 5
int ttransit [NBETATS][NBTYPES] = { { 1, 3, 2, -1, -1, -1 } ,
						    	    { 1, 3, 4, 10, 10, 10 } ,
								    { 1, -1, -1, -1, -1, -1 } ,
								    { 3, -1, -1, -1, -1, -1 } ,
								    { 4, -1, -1, -1, -1, -1 } };

void affiche_ttransit(int (*)[NBTYPES]);
void genere_dot(int (*)[NBTYPES]);
enum types get_type(char);
void print_typ(char *);



extern char *s;


// appliquer la moulinette sur str pour lire un nombre
// deplacer le pointeur global s sur apres le nombre lu
// le nombre lu est dans elt
// l'etat final est retourne
int automate(char *str, int etat, char *elt) {
int i;
enum types t;
	for (i=0 ; str[i]!='\0' ; i++) {
		t = get_type(str[i]);
		etat = ttransit[etat][t];
		if (etat==ETATSORTIE || etat==ETATERREUR) {
			s=&str[i];
			elt[i]='\0';
			return etat;
		}
		elt[i]=str[i];
	}
	// str[i] contient '\0', donc un SEP
	etat = ttransit[etat][SEP];
	s = &str[i];
	elt[i]='\0';
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
		case '.': return POINT; break;
		case '+': return SIGNE; break;
		case '-': return SIGNE; break;
		case ' ': return SEP; break;
		case ',': return SEP; break;
		case ';': return SEP; break;
		case '(': return SEP; break;
		case ')': return SEP; break;
		case '\0': return SEP; break;
		case '\n': return SEP; break;
	}
	if (l >= '0' && l<='9')
		return CHIFFRE;
	if (l>='a'&&l<='z' || l<='A'&&l<='Z')
		return LETTRE;
	// dans tous les autres cas
	return AUTRE;
}


//  CHIFFRE, POINT, SIGNE, SEP, LETTRE, AUTRE
void affiche_ttransit(int tab[NBETATS][NBTYPES]) {
int i, j;
	printf("ETAT | CHI | POI | SIG | SEP | LET | AUT |\n");
	for (i=0 ; i<NBETATS ; i++) {
		printf("  %2d |  ", i);
		for (j=0 ; j<NBTYPES ; j++) {
			printf("%2d |  ", tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// genere dot correspondant a un automate
void genere_dot(int tab[NBETATS][NBTYPES]) {
int i, j, flag;
char *types[]={ "0-9", ".", "+-", "sep", "a-z", "AUT" };
FILE *fp;
	fp = fopen("automate.dot", "w");
	if (fp==NULL) {
		perror("Pb pour ouvrir le fichier");
		exit(1);
	}
//  concentrate=\"true\"
	fprintf(fp, "digraph G { \n rankdir=\"LR\" \n  \n");
	for (i=0 ; i<NBETATS ; i++) {
		flag=0;
		for (j=0 ; j<NBTYPES ; j++) {
		   if(ttransit[i][j] == -1) {
			if (flag==1)
				continue;
			fprintf(fp, " %d -> %d [label=\"A\"]\n", i, ttransit[i][j]);
			flag=1;
		   } else {
			fprintf(fp, " %d -> %d [label=\"%s\"]\n", i, ttransit[i][j], types[j]);
		   }
		}
	}
	fprintf(fp, "10 [style=\"filled\", color=\"green\"]\n");
	fprintf(fp, "-1 [style=\"filled\", color=\"red\"]\n");

	fprintf(fp, "}\n\n");
	fclose(fp);
}

void affiche_automate(void) {
	affiche_ttransit(ttransit);
	genere_dot(ttransit);
}
