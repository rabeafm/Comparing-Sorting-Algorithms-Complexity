#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

/*****************************************************************
 *  Main Method in program, prints introduction and requests for *
 *  N - Number of numbers, creates an array of random numbers    *
 *  then runs each of the different strategies on a clone of the *
 *  created array.                                               *
 ****************************************************************/
int main () {
    int *arr, N;

    printf ( "******************************************************************************************\n" );
    printf ( "* Welcome to exercise 14 in the course Introduction to Algorithems & Data Structures.    *\n" );
    printf ( "* This program presents how different Algorithems can achieve different complexity in    *\n" );
    printf ( "* solving the same problem. In this case it is counting how many unique numbers are in   *\n" );
    printf ( "* a randomly generated array.                                                            *\n" );
    printf ( "* The measurement of the Complexity is done using counters of Assignments, Copying and   *\n" );
    printf ( "* comparisons for each and every algorithem.                                             *\n" );
    printf ( "******************************************************************************************\n" );
    printf ( " Please insert a length for the array: " ); 

        /*(shouldn't be larger than 1000000 unless you have patience and a realy good computer):*/
    scanf ( "%d", &N );
    
    arr = createNumsArray ( N );
    printf ( "******************************************************************************************\n" );

    printf ( "For an Array of length: %d\n\n", N);

                    /*  Run Different Strategies to solve given problem */ 
    printf ( "******************************** Original D algorithem ***********************************\n" );
    useStrategy ( noSort, originalD, arr, N );

    printf ( "********************************* Using Insertion Sort ***********************************\n" );
    useStrategy ( insertionSort, countUniques, arr, N );

    printf ( "*********************************** Using Merge Sort *************************************\n" );
    useStrategy ( mergeSortI, countUniques, arr, N );

    printf ( "*********************************** Using Count Sort *************************************\n" );
    useStrategy ( countSort, countUniques, arr, N );

    printf ( "*********************************** Using Hash Table *************************************\n");
    M=1+sqrt(N);
    useStrategy ( noSort , makehash, arr, N );

    printf ( "******************************* Using Binary Search Tree *********************************\n" );
    useStrategy ( noSort, makeBST, arr, N );

    printf ( "********************************* Using Red Black Tree ***********************************\n" );

//    makeRBT();
//    useStrategy ( noSort, makeRBT, arr, N );

    free ( arr );
    return 1;
}


