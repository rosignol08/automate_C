/* ---------------------------------------------------------------

   Expressions mathematiques
   Reconnaissance de nb flottants ou entiers
   avec automate et table de transition

   F. Balmas   mars 2021

   ---------------------------------------------------------------
*/

#define ETATENTREE 0
#define ETATSORTIE 10
#define ETATERREUR -1

int automate(char *, int, char *);
