// Range for the C array in the count sort
#define CRANGE 101

// Global variables HASHSIZE, and counters intialized to 0 automatically
int HASHSIZE;
long assign,cpy,cmp;

// utilities functions
int * createNumsArray ( int );
int * cloneNumsArray ( int *, int );
void merge ( int *, int, int, int );
void printArray ( int *, int );
void useStrategy ( void ( int *, int ), int ( int *, int ), int *, int );

// stage 1 functions for sorting
void noSort ( int *, int );
void insertionSort ( int*, int );
void mergeSortI ( int *, int );
int countSort ( int *, int );

// stage 2 functions for counting uniques
int originalD ( int *, int );
int countUniques ( int *, int );
int countCUniques ( int *, int );
int makeHash ( int *, int );
int makeBST ( int *, int );
