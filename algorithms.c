#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

/*****************************************************************
 *  Receives an array of numbers, itirates through them counting *
 *  the number of unique numbers in the array.                   *
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 *  @return number of unique numbers                			 *
 ****************************************************************/
int originalD(int arr[], int N){
    int U_Size = 1,U,i,j;   
    /* Intialize assignment,copy & comparison counters (includes declaration & loop) */
    assign=2; cpy=0; cmp=1;
    for(i=1;i<N;i++){           /* Init i=1 instead of i=2 in pseudocode */
        assign+=2; cmp++;
        U=1;                    /* Init U=1 instead of U=True in pseudocode */
        for(j=0;j<U_Size;j++){  /* Init j=0 instead of j=1 in pseudocode */
            cmp++;
            if(arr[j]==arr[i]){
                assign+=2;
                U=0;            /* Init U=0 instead of U=False in pseudocode */
                j=U_Size;       
            }
            assign++; cmp++;
        }
        cmp++;
        if(U==1){
            assign++; cpy++;
            U_Size++;
            arr[U_Size-1]=arr[i];/* Correction of U_Size when used as index */
        }
        assign++; cmp++;
    }
    return U_Size;
}

/*****************************************************************
 *  Receives a sorted array of numbers, counts number of unique  *
 *  numbers & returns it.                                        *
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

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
void mergeSortI(int arr[], int N){
    mergeSort(arr,0,N-1);
}

 

#define RANGE 255
 
// The main function that sort the given string arr[] in
// alphabatical order
void countSort(int arr[],int N)
{
    // The output character array that will have sorted arr
    int output[N];
 
    // Create a count array to store count of inidividul
    // characters and initialize count array as 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
 
    // Store count of each character
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];
 
    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];
 
    // Build the output character array
    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
 
    /*
     For Stable algorithm
     for (i = sizeof(arr)-1; i>=0; --i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
    
    For Logic : See implementation
    */
 
    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}