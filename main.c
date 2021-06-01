#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


int main(){
    int N,tmp;
    int *arr,*tmparr;

    printf("***************************************************************************\n");
    printf("* Welcome to exercise 14 in the course Introduction to Algorithems & Data *\n");
    printf("* Structures. This program presents how different Algorithems can present *\n");
    printf("* different complexity in solving the same problem, which is counting how *\n");
    printf("* many unique numbers are in a randomly generated array.                  *\n");
    printf("* The measurement of the Complexity is done using counters of assignments,*\n");
    printf("* copying & comparisons for each and every algorithem.                    *\n");
    printf("* Please insert a length for the array: "); /*(shouldn't be larger than 1000000 unless you have patience and a realy good computer):*/
    scanf("%d",&N);
    arr = createNumsArray(N);
    printf("***************************************************************************\n\n"); 

    /* Cloning array to make comparison accurate */
    tmparr = cloneNumsArray(arr,N);
    tmp=originalD(tmparr,N);
    printf("******************* Array for the original D algorithem *******************\n");
    printf("Results of original D algorithem - Unique Numbers: %d \n\n\t  Assignments: %d \t Copies: %d \t Comparisons: %d \n",tmp,assign,cpy,cmp);
    printf("***************************************************************************\n\n");
    free(tmparr);

    tmparr = cloneNumsArray(arr,N);
    insertionSort(tmparr,N);
    tmp=countUniques(tmparr,N);
    printf("*********************** Array after Insertion sort ************************\n");
    printArray(tmparr,N);
    printf("***************************************************************************\n");
    printf("Results of counting after insertion sort algorithem - Unique Numbers: %d \n\n\t  Assignments: %d \t Copies: %d \t Comparisons: %d \n",tmp,assign,cpy,cmp);
    printf("***************************************************************************\n");
    free(tmparr);

    
    //printArray(arr,N);
    free(arr);
    return 1;
}

/*****************************************************************
 *  Receives a length of an array, creates an array of random    *
 *  numbers in the range 1-100.                                  *
 *  @param	N				length of the array                  *
 *  @return pointer to an array of numbers                		 *
 ****************************************************************/
int * createNumsArray(int N){
    int i,sum=0;            /* sum is used as an indicator of numbers ditribution */
    int *arr;
    srand(time(NULL));
    arr = (int *) malloc(N*sizeof(int));
    for(i = 0 ; i < N ; i++) {
        arr[i]=rand()%100+1;
        sum+=arr[i];
    }
    printf("* Random numbers array created (Sum is: %d, Avg is: %d):                 *\n",sum,sum/N);
    printArray(arr,N);
    return arr;
}

/*****************************************************************
 *  Receives an array & its length, clones it & returns a copy   *
 *  @param	arr				An array                             *
 *  @param	N				length of the array                  *
 *  @return pointer to a cloned array of numbers                 *
 ****************************************************************/
int * cloneNumsArray(int arr[],int N){
    int i;            /* sum is used as an indicator of numbers ditribution */
    int *tmparr;
    tmparr = (int *) malloc(N*sizeof(int));
    for(i = 0 ; i < N ; i++) {
        tmparr[i]=arr[i];
    }
    return tmparr;
}

/*****************************************************************
 *  Receives an array of numbers, itirates through the array and *
 *  prints them.                                                 *
 *  @param	arr             Array of numbers                     *
 *  @param	N				length of the array                  *
 ****************************************************************/
void printArray(int arr[], int N){
    int i;
    for( i=0 ; i<N ; i++ ){
        printf("%d", arr[i]);
        ((i%10==9)&&(i!=N-1)?printf("\n"):printf("\t"));
    }
    printf("\n");
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







/*  int hashSort(int [] A){}
    int binarySearchSort(int [] A){}
    int redBlackTreeSort(int [] A){}    */