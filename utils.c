#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "header.h"

/*****************************************************************
 *  Receives a length of an array, creates an array of random    *
 *  numbers in the range 1-100. runs at O(n).                    *
 *  @param	N				length of the array                  *
 *  @return pointer to an array of numbers                		 *
 ****************************************************************/
int *createNumsArray ( int N ) {
    int *arr, i, sum = 0;            /* sum is used as an indicator of numbers ditribution */
    srand ( time ( NULL ) );
    arr = (int *) malloc ( N * sizeof(int) );
    for ( i = 0 ; i < N ; i++ ) {
        arr [ i ] = rand() % 100 + 1;
        sum += arr [ i ];
    }
    printf ( " Random numbers array created (Sum is: %d, Avg is: %d):\n", sum, sum/N );
    printArray ( arr, N );
    return arr;
}

/*****************************************************************
 *  Receives an array & its length, clones it and returns a      *
 *  pointer to a copy. runs at O(n).                             *
 *  @param	arr				An array                             *
 *  @param	N				length of the array                  *
 *  @return pointer to a cloned array of numbers                 *
 ****************************************************************/
int *cloneNumsArray ( int arr[], int N ) {
    int *tmparr, i;
    tmparr = (int *) malloc ( N * sizeof(int) );
    for ( i = 0 ; i < N ; i++ ) {
        tmparr [ i ] = arr [ i ];
    }
    return tmparr;
}

/*****************************************************************
 *  Receives an array & three indexes which define sorted sub    *
 *  arrays. merges them and creates a sorted array, runs at O(n).*
 *  @param	arr				An array                             *
 *  @param	p				left index                           *
 *  @param	q				mid index                            *
 *  @param	r				right index                          *
 ****************************************************************/
void merge(int arr[], int p, int q, int r) {
    int i, j, k;
    int n1 = q-p+1;
    int n2 = r-q;
    int L [ n1+1 ], R [ n2+1 ];     /* create arrays */
 
    /* Fill data in arrays L[] and R[] */
    assign += 3; cmp++;
    for ( i = 0 ; i < n1 ; i++ ) {
        cpy++;
        L [ i ] = arr [ p+i ];
        assign++; cmp++;
    }
    assign++; cmp++;
    for ( j = 0 ; j < n2 ; j++ ) {
        cpy++;
        R [ j ] = arr [ q+j+1 ];
        assign++; cmp++;
    }
    cpy += 2;
    L [ n1 ] = INT_MAX;
    R [ n2 ] = INT_MAX;

    /* Merge the arrays L[] & R[] into arr[p-r]*/
    assign += 3; cmp++;
    for ( i = 0, j = 0, k = p ; k <= r ; k++ ) {
        cmp++;
        if ( L [ i ] <= R [ j ] ) {
            cpy++; assign++;
            arr [ k ] = L [ i ];
            i++;
        } else {
            cpy++; assign++;
            arr [ k ] = R [ j ];
            j++;
        }
        assign++; cmp++; 
    }
}

/*****************************************************************
 *  Receives an array of numbers, itirates through the array and *
 *  prints them. runs at O(n).                                   *
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 ****************************************************************/
void printArray ( int arr[], int N ) {
    int i;
    for( i = 0 ; i < N ; i++ ) {
        printf ( " %d", arr [ i ] );
        ( ( ( i%10 == 9 ) || ( i == N-1 ) ) ? printf ( "\n" ) : printf ( "\t" ) );
    }
}

/*****************************************************************
 *  Receives 2 functions, an Array and a length. The array is    *
 *  cloned, and the first function which is (sort/convert) is    *
 *  activated on the temporary array, then the second function   *
 *  is activated to count for unique numbers. runs at O(1).      *
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 ****************************************************************/
void useStrategy(void sort(int *, int), int count(int *, int), int arr[], int N){
    int *tmparr;
    int tmpcnt;
    assign = 0; cpy = 0; cmp = 0;       /* Initialize counters for strategy */
    tmparr = cloneNumsArray(arr, N);
    sort(tmparr, N);
    tmpcnt = count(tmparr, N);
    printf("Unique Numbers: %d \t Assignments: %ld \t Copies: %ld \t Comparisons: %ld \n\n", tmpcnt, assign, cpy, cmp);
    //printArray(tmparr,N);
    free(tmparr);
}