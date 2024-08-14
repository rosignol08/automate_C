/* ------------------------------------------------

   Arbres binaires : declarations

   F. Balmas, mars 2021

   ------------------------------------------------ */


struct arbre {
  char val;
  struct arbre *G;
  struct arbre *D;
};

typedef struct arbre *TREE;


TREE cree_arbre( char x );

void affiche_pre( TREE a );
void affiche_in( TREE a );
void affiche_post( TREE a );

// pour d'autres versions de arbre.c ...
void affiche_in_tr( TREE a , TREE pos );
