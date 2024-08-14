/************************************************************
*
*   Ce fichier contient les declarations necessaires pour
*    utiliser la librairie list
*
*   F. Balmas 2021
*
*************************************************************/


struct linked {
    char nom[8]; // le nom, max 7 char
    struct linked *cell; // pointeur sur le chainon suivant
};



// creation du type LINKED pour simplifier les declarations
typedef struct linked *LINKED;

// alloue un chainon
LINKED alloc_list(void);
//struct linked *alloc_list(void);

// ajoute un chainon au debut de la liste
void add_begin (LINKED t, LINKED l);

// affiche le contenu d'une liste
void print_list(LINKED l);
void print_list_compact(LINKED l);

// teste si un elt appartient a une liste
LINKED member (char *x, LINKED l);

// initialise la liste
void init_list(LINKED p);

// initialise la freeliste
void init_freeliste(void);

// affiche un chainon
void print_nom(LINKED p);

// calcule la longueur de la liste
int length(LINKED l);

extern long nbbi;
