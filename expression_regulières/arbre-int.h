/* ------------------------------------------------

   Arbres binaires : declarations

   F. Balmas, mars 2021

   ------------------------------------------------ */


struct arbre {
  int val;
  struct arbre *G;
  struct arbre *D;
};

typedef struct arbre *TREE;

#define VALUE(a) (a->val)
#define LEFT(a) (a->G)
#define RIGHT(a) (a->D)

TREE cree_arbre( int x );

void affiche_pre( TREE a );
void affiche_in( TREE a );
void affiche_post( TREE a );

// pour d'autres versions de arbre.c ...
void affiche_in_tr( TREE a , TREE pos );
