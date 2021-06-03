#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

/*****************************************************************
 *  Receives an array of numbers, itirates through them counting *
 *  the number of unique numbers in the array at O(n^2).         *
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 *  @return number of unique numbers                			 *
 ****************************************************************/
int originalD ( int arr[], int N ) {
    int U_Size = 1, U, i, j;   
    /* Intialize assignment,copy & comparison counters (includes declaration & loop) */
    assign = 2; cpy = 0; cmp = 1;
    for ( i = 1 ; i < N ; i++ ) {           /* Init i=1 instead of i=2 in pseudocode */
        assign += 2; cmp++;
        U = 1;                              /* Init U=1 instead of U=True in pseudocode */
        for( j = 0 ; j < U_Size ; j++ ) {   /* Init j=0 instead of j=1 in pseudocode */
            cmp++;
            if( arr[j] == arr[i] ) {
                assign += 2;
                U = 0;                      /* Init U=0 instead of U=False in pseudocode */
                j = U_Size;       
            }
            assign++; cmp++;
        }
        cmp++;
        if ( U == 1 ) {
            assign++; cpy++;
            U_Size++;
            arr[U_Size-1] = arr[i];         /* Correction of U_Size when used as index */
        }
        assign++; cmp++;
    }
    return U_Size;
}

/*****************************************************************
 *  Receives a sorted array of numbers, counts number of unique  *
 *  numbers & returns it at O(n).                                *
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 *  @return number of unique numbers in array                    *
 ****************************************************************/
int countUniques(int arr[], int N){
    int i,cnt=1;
    assign+=2; cmp++;
    for( i=1 ; i<N ; i++ ){
        cmp++;
        if(arr[i]!=arr[i-1]){
            assign++;
            cnt++;
        }
        assign++; cmp++;
    }
    return cnt;
}

/*****************************************************************
 *  Receives a numbers array and a length, does nothing at O(1). *
 *  Created to be used as a placeholder in useStrategy function. *  
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 ****************************************************************/
void noSort(int arr[], int N){}

/*****************************************************************
 *  Receives an array & its length, sorts it at O(n^2).          *
 *  @param	arr				An array                             *
 *  @param	N				length of the array                  *
 ****************************************************************/
void insertionSort(int arr[], int N){
    int j, key, i;
    assign++; cmp++;
    for ( j=1 ; j<N ; j++ ){
        assign++; cpy++; cmp+=2;
        key = arr[j];
        i = j-1;
        while ( i>=0 && arr[i]>key ){
            cpy++; assign++;
            arr[i+1] = arr[i];
            i = i-1;
        }
        cpy++;
        arr[i+1] = key;
        assign++; cmp++;
    }
}

/*****************************************************************
 *  Receives an array, an index to first cell and an index to    *
 *  last cell. if the array is bigger than 1 cell divides to 2   *
 *  arrays (using indexes) and calls it self, if is 1 cell uses  *
 *  merge to rearrange array in a sorted way, runs at O(nlogn).  *
 *  @param	arr				An array                             *
 *  @param	p				left index                           *
 *  @param	r				right index                          *
 ****************************************************************/
void mergeSort ( int arr[], int p, int r ) {
    cmp++;
    if ( p<r ) {
        assign++;
        int q = (p + r) / 2;
        // Divide & Sort
        mergeSort ( arr, p, q );
        mergeSort ( arr, q+1, r );
        merge ( arr, p, q, r );
    }
}

/*****************************************************************
 *  Receives a numbers array and a length, calls merge sort with *
 *  proper parameters. used as an Interface for merge sort.      *
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 ****************************************************************/
void mergeSortI ( int arr[], int N ) {
    mergeSort ( arr, 0, N-1 );
}
 
/*****************************************************************
 *  Receives an array & its length, sorts it at O(n).            *
 *  @param	arr				An array                             *
 *  @param	N				length of the array                  *
 ****************************************************************/
void countSort(int arr[],int N){
    int B[N], C[CRANGE+1]; //Arrays B as temporary & C for Counting Appearances
    int i, j; 
    
    assign++; cmp++;
    for ( i = 0 ; i <= CRANGE ; i++){        // Initialize count array as 0
        cpy++;
        C [ i ] = 0;
        assign++; cmp++;
    }

    assign++; cmp++;
    for ( j = 0 ; j < N ; j++ ) {           // Increase counter for given value
        assign++;
        C[ arr [ j ] ]++;
        assign++; cmp++;
    }
 
    assign++; cmp++;
    for ( i = 1 ; i <= CRANGE ; i++ ) {     // Change count[i] so that count[i] now contains actual position of this character in output array
        assign++;
        C[i] += C[i - 1];
        assign++; cmp++;
    }
 
    assign++; cmp++;
    for ( j = N-1 ; j>=0 ; j-- ) {          // Build the output character array
        cpy++;
        B[C[arr[j]]-1] = arr[j];
        assign++;
        C[arr[j]]--;
        assign++; cmp++;
    }

    assign++; cmp++;
    for (i = 0; i<N ; i++){
        cpy++;
        arr[i] = B[i];
        assign++; cmp++;
    }
}