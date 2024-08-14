/* ------------------------------------------------

   Arbres binaires : declarations

   R. chaffray avril 2024

   ------------------------------------------------ */


struct arbre {
  float val;
  struct arbre *G;
  struct arbre *D;
};

typedef struct arbre *TREE;

#define VALUE(a) (a->val)
#define LEFT(a) (a->G)
#define RIGHT(a) (a->D)

TREE cree_arbre( float x );

void affiche_pre( TREE a );
void affiche_in( TREE a );
void affiche_post( TREE a );

// pour d'autres versions de arbre.c ...
void affiche_in_tr( TREE a , TREE pos );
