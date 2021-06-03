#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

/*****************************************************************
 *  Receives a length of an array, creates an array of random    *
 *  numbers in the range 1-100.                                  *
 *  @param	N				length of the array                  *
 *  @return pointer to an array of numbers                		 *
 ****************************************************************/
int *createNumsArray(int N){
    int i,sum=0;            /* sum is used as an indicator of numbers ditribution */
    int *arr;
    srand(time(NULL));
    arr=(int *)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        arr[i]=rand()%100+1;
        sum+=arr[i];
    }
    printf("* Random numbers array created (Sum is: %d, Avg is: %d):                          \n",sum,sum/N);
    printArray(arr,N);
    return arr;
}

/*****************************************************************
 *  Receives an array & its length, clones it & returns a copy   *
 *  @param	arr				An array                             *
 *  @param	N				length of the array                  *
 *  @return pointer to a cloned array of numbers                 *
 ****************************************************************/
int *cloneNumsArray(int arr[],int N){
    int i;            /* sum is used as an indicator of numbers ditribution */
    int *tmparr;
    tmparr=(int *)malloc(N*sizeof(int));
    for (i=0 ; i<N ; i++) {
        tmparr[i]=arr[i];
    }
    return tmparr;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*****************************************************************
 *  Receives an array of numbers, itirates through the array and *
 *  prints them.                                                 *
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 ****************************************************************/
void printArray(int arr[], int N){
    int i;
    printf("* ");
    for( i=0 ; i<N ; i++ ){
        printf(" %d", arr[i]);
        ((i%10==9||(i==N-1))?printf("\n*"):printf("\t"));
    }
}

void useStrategy(void sort(int *, int), int count(int *, int), int arr[], int N){
    int *tmparr;
    int tmpcnt;
    assign = 0; cpy = 0; cmp = 0;
    tmparr = cloneNumsArray(arr, N);
    sort(tmparr, N);
    tmpcnt = count(tmparr, N);
    printf("Unique Numbers: %d \t Assignments: %d \t Copies: %d \t Comparisons: %d \n\n", tmpcnt, assign, cpy, cmp);
    //printf("***************************************************************************\n\n");
    free(tmparr);
}