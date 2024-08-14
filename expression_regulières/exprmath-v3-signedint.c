/* ------------------------------------------------

   Expr math simples : représentation et calcul
   au moyen des arbres binaires
   Détection des erreurs à la création + trap
   des erreurs
   Lecture des nombres avec un automate

   F. Balmas, mars 2022

   ------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include "arbre-float.h"
#include "automate.h"

void ajouter_expr(TREE);
void ajouter_term(TREE);
void ajouter_operateur(TREE);
void print_expr(TREE);
float compute_expr(TREE);

#define NOMBRE(a) ((a)->G == NULL)

char *messages[]= { "", "erreur operande", "erreur operateur" };

char expr[BUFSIZ];
char *s;
jmp_buf env;

void main()
{
  int res, err;
  TREE racine;

  affiche_automate();

  err=setjmp(env);
  if (err != 0) {
    printf("%s\n", messages[err]);
  }

  while (1)
    {
      int i;
      printf("--> ");
      fgets(expr, BUFSIZ, stdin);

      if (expr[0]=='.')
		      break;

      // substituer \n par \0, pour affichage ...
      for(i=0 ; expr[i]!='\n' ; i++);
      expr[i]='\0';

      s=expr;

      racine = cree_arbre( 0 );
      ajouter_expr(racine);
/*
      // affichages pre- in- et post- fixe de l'arbre genere
      printf("Pre : ");
      affiche_pre(racine);
      printf("\nIn : ");
      affiche_in(racine);
      printf("\nPost : ");
      affiche_post(racine);
*/

      printf("Lu : ");
      print_expr(racine);
      printf("\n");

      res = compute_expr(racine);
      printf("Valeur = %d\n\n", res);
    }
}

void ajouter_expr(TREE a)
{
  if (*s != '\0')
    {
      a->G=cree_arbre(0);
      ajouter_term(a->G);
      ajouter_operateur(a);
      a->D=cree_arbre(0);
      ajouter_term(a->D);
    }
}

void ajouter_operateur(TREE a) {
  char op;
  op=*s;
  if (op=='+' || op=='-' || op=='*' || op=='/') {
    a->val = (int)*s;
    s++;
  }
  else {
    printf("|%c|  ", *s);
    longjmp(env, 2);
  }
}

// 1er cas parenthese ouvrante
// sinon supposer nb, chercher nb (max) avec automate
// si ok integrer et continuer
// sinon gerer l'erreur
void ajouter_term(TREE a)
{
  char buf[20];
  float etat;
  if (*s == '(') {
    s++;
    ajouter_expr(a);
    s++; /* on suppose ici la parenthese droite */
  } else if ((*s >= '0' && *s <= '9') || (*s == '-') || (*s == '+')) {
    etat = automate(s, ETATENTREE, buf);
    // tester l'etat de sortie
    // printf("lu %s etat %d\n", buf, etat);
    if (etat == ETATERREUR) {
        // lu juste le signe, sans chiffre/nombre derriere
        printf("|%s|  ", buf);
        longjmp(env, 1);
    }
    a->val = atof(buf);
    // s est déplace dans automate
    // s++;
  }
  else {
    printf("|%c|  ", *s);
    longjmp(env,1);
  }
}

void print_expr(TREE a)
{
  if ( NOMBRE(a) )
    {
      printf("%f", a->val);
    }
  else
    {
      printf("(");
      print_expr(a->G);
      printf(" %f ", (float)a->val);
      print_expr(a->D);
      printf(")");
    }
}

float compute_expr(TREE a)
{
  float v1, v2;
  if ( NOMBRE(a) )
    {
      return(a->val);
    }
  else
    {
      v1 = compute_expr(a->G);
      v2 = compute_expr(a->D);
      if ((char)a->val == '+')
		    return(v1 + v2);
      if ((char)a->val == '*')
		    return(v1 * v2);
      if ((char)a->val == '-')
		    return(v1 - v2);
      if ((char)a->val == '/')
		    return(v1 / v2);
    }
}



/* traces d'execution


*/
