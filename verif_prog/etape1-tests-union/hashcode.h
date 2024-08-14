/* ***************************************************************
*
*  Hashcoding
*
*  F. Balmas 2021
*
******************************************************************/
//#define N 53
#define N 13

extern LINKED tabhash[N];

LINKED search_nom(char *nom);
void add_nom(char *s);
 int compute_hash (char *word);
void init_tabhash(void);
void print_tabhash(void);
void print_tabhash_compact(void);
