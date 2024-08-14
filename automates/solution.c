/* ---------------------------------------------------------------

   Tests automates et tables de transitions
   Solution des exercices, a copier dans le fichier .c

   F. Balmas   mars 2024

   ---------------------------------------------------------------
*/

#ifdef T1
// accepte nb impair
// [01]*1
int ttransit [NBETATS][NBTYPES] = { { 'A', 'B' } ,
			    	    			{ 'A', 'B' } };
#endif

#ifdef T2
// accepte nb pair
// [01]*0
int ttransit [NBETATS][NBTYPES] = { { 'B', 'A' },
                                    { 'B', 'A' } };
#endif

#ifdef T3
// nb impair de zero
// (1*01*)(1*01*01*)*
int ttransit [NBETATS][NBTYPES] = { { 'B', 'A' },
                                    { 'A', 'B' } };
#endif

#ifdef T4
// nb pair de zero
// (1*01*01*)*
int ttransit [NBETATS][NBTYPES] = { { 'B', 'A' },
                                    { 'A', 'B' } };
#define ETATSORTIE 'A'
#define ETATERREUR 'B'
#endif

#ifdef T5
// nb pair mais non nul de zero
// (1*01*01*)+
#define NBETATS 3
int ttransit [NBETATS][NBTYPES] = { { 'B', 'A' },
				    				{ 'C', 'B' },
				    				{ 'B', 'C' } };
#define ETATSORTIE 'C'
#define ETATERREUR 'A'    // ou B ...
#endif

#ifdef T6
// accepte 2 zero qui se suivent
// [01]*00[01]*
#define NBETATS 3
int ttransit [NBETATS][NBTYPES] = { { 'B', 'A' },
				     				{ 'C', 'A' },
                                    { 'C', 'C' } };
#define ETATSORTIE 'C'
#define ETATERREUR 'A'    // ou B ...
#endif

#ifdef T7
// accepte 1 puissance de 2
// 10*
#define NBETATS 3
int ttransit [NBETATS][NBTYPES] = { { 'A', 'B' },
				     				{ 'B', 'C' },
                                    { 'C', 'C' } };
#define ETATSORTIE 'B'
#define ETATERREUR 'C'    // ou B ...
#endif