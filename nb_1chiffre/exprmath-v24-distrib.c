/* ------------------------------------------------

   Expr math simples : représentation et calcul
   au moyen des arbres binaires
   Détection des erreurs à la création + trap
   des erreurs

   F. Balmas, mars 2022

   ------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include "arbre.h"

void ajouter_expr(TREE);
void ajouter_term(TREE);
void ajouter_operateur(TREE);
void print_expr(TREE);
int compute_expr(TREE);

#define NOMBRE(a) (a->val>='0' && a->val<='9')

char *messages[]= { "", "erreur operande", "erreur operateur", "erreur rpar manquante","erreur Division par 0" };

char expr[BUFSIZ];
char *s;
jmp_buf env;

void main()
{
  int res, err;
  TREE racine;


  err=setjmp(env);
  if (err != 0) {
    printf("%s\n", messages[err]);
  }

  int i;

  while (1)
    {
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
  while (op==' ') {
    s++;
    op=*s;
  }
  if (op=='+' || op=='-' || op=='*' || op=='/' || op=='%') {
    a->val = *s;
    s++;
  }
  else {
    printf("|%c|  ", *s);
    longjmp(env, 2);
  }
}
void ajouter_term(TREE a){
  char op;
  op=*s;
  while (op==' ') {
    s++;
    op=*s;
  }
  if (*s >= '0' && *s <= '9')
    {
      a->val = *s;
      s++;
    }
  if (*s >= '0' && *s <= '9'){
    //printf("|%c|  ", *s);
    longjmp(env, 1);
  }
  else if (*s == '('){
    op=*s;
    while (op==' ') {
      s++;
      op=*s;
    }
      s++;
      ajouter_expr(a);
      op=*s;
      while (op==' ') {
        s++;
        op=*s;
      }
      if (*s != ')') {
        printf("|%c|  ", *s);
        longjmp(env, 3);
      }
      char op;
      op=*s;
      while (op==' ') {
        s++;
        op=*s;
      }
      s++;  /* ici la parenthese droite */
    }
  else {
    printf("|%c|  ", *s);
    //longjmp(env,1);
  }
}

void print_expr(TREE a)
{
  if ( NOMBRE(a) )
    {
      printf("%c", a->val);
    }
  else
    {
      printf("(");
      print_expr(a->G);
      printf(" %c ", a->val);
      print_expr(a->D);
      printf(")");
    }
}

int compute_expr(TREE a)
{
  int v1, v2;
  if ( NOMBRE(a) )
    {
      return(a->val-48);
    }
  else
    {
      v1 = compute_expr(a->G);
      v2 = compute_expr(a->D);
      if (a->val == '+')
		return(v1 + v2);
      if (a->val == '*')
		return(v1 * v2);
      if (a->val == '-')
		return(v1 - v2);
      if (a->val == '/'){
        if (v2 == 0){
          longjmp(env, 4);
        }
      }
		return(v1 / v2);
      if (a->val == '%'){
        if (v2 == 0){
          longjmp(env, 4);
        }
      }
    return(v1 % v2);
    }
    return 500;
}



/* traces d'execution

   --> 8-7
   Expr : 8-7
   Pre : - 8 7
   In : 8 - 7
   Post : 8 7 -

   Lisp :  (- 8 7)
   Valeur = 1


   --> 5+ 6
   Expr : 5+ 6
   | |  erreur operande dans un term


   --> 3 *8
   Expr : 3 *8
   | |  erreur operateur


   --> 5+()
   Expr : 5+()
   |)|  erreur operande dans un term


*/



