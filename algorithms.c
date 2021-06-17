#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "header.h"

/*****************************************************************
 *  Receives a numbers array and a length, does nothing at O(1). *
 *  Created to be used as a placeholder in useStrategy function. *  
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 ****************************************************************/
void noSort ( int arr[], int N ) {}

/*****************************************************************
 *  Receives an array of numbers, itirates through them counting *
 *  the number of unique numbers in the array at O(NM).(M=RANGE) *
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
 *  Receives an array & its length, sorts it at O(n^2).          *
 *  @param	arr				An array                             *
 *  @param	N				length of the array                  *
 ****************************************************************/
void insertionSort ( int arr[], int N ) {
    int j, key, i;
    assign++; cmp++;
    for ( j = 1 ; j < N ; j++ ) {
        assign++; cpy++; cmp+=2;
        key = arr [ j ];
        i = j-1;
        while ( i >= 0 && arr [ i ] > key ) {
            cpy++; assign++;
            arr [ i+1 ] = arr [ i ];
            i = i-1;
            cmp++;
        }
        cpy++;
        arr [ i+1 ] = key;
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
    if ( p < r ) {
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
 *  Receives an array & three indexes which define sorted sub    *
 *  arrays. merges them and creates a sorted array, runs at O(n).*
 *  @param	arr				An array                             *
 *  @param	p				left index                           *
 *  @param	q				mid index                            *
 *  @param	r				right index                          *
 ****************************************************************/
void merge ( int arr[], int p, int q, int r ) {
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
 *  Receives a sorted array of numbers, counts number of unique  *
 *  numbers & returns it at O(n).                                *
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 *  @return number of unique numbers in array                    *
 ****************************************************************/
int countUniques ( int arr[], int N ) {
    int i, cnt=1;
    assign+=2; cmp++;
    for ( i = 1 ; i < N ; i++ ) {
        cmp++;
        if ( arr [ i ] != arr [ i-1 ] ) {
            assign++;
            cnt++;
        }
        assign++; cmp++;
    }
    return cnt;
}
 
/*****************************************************************
 *  Receives an array & its length, counts apearances of each    *
 *  number in array C, then copies C to input array runs at O(n).*
 *  @param	arr				An array                             *
 *  @param	N				length of the array                  *
 ****************************************************************/
int countSort(int *arr,int N){
    int C[CRANGE]; //Array C for temporary Counting
    int i;
 
    // Initialize C array as 0
    assign++; cmp++;
    for ( i = 0 ; i < CRANGE ; i++){        
        assign++;
        C [ i ] = 0;
        assign++; cmp++;
    }

    // Increase C counter cells for given value
    assign++; cmp++;
    for ( i = 0 ; i < N ; i++ ) {           
        assign++;
        C [ arr [ i ] ]++;
        assign++; cmp++;
    }

    return countCUniques(C,CRANGE);
}

/*****************************************************************
 *  Receives an array of ocorrences of numbers, counts none zero *
 *  cells, runs at O(N), in this case O(M). (M=CRANGE)           *
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 *  @return number of unique numbers in array                    *
 ****************************************************************/
int countCUniques(int arr[], int N){
    int i,cnt=0;
    assign+=2; cmp++;
    for( i=1 ; i < CRANGE ; i++ ){
        cmp++;
        if(arr[i]!=0){
            assign++;
            cnt++;
        }
        assign++; cmp++;
    }
    return cnt;
}