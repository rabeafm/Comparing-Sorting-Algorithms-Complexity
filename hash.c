#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

struct LinkedNode
{
    int data;
    struct LinkedNode *next;
};

struct LinkedNode **hashTable; 

/*****************************************************************
 *  Recieves int uses multiplication hash function. runs at O(1) *
 *  @param	k    		integer                                  *
 *  @return number that represents address in hash table         *
 ****************************************************************/
int hashCode(int k) {
   return (int) HASHSIZE * fmodf((sqrt(5)-1)*k,1);
}

/*****************************************************************
 *  Recieves key and data adds data to linked list in key address*
 *  runs at O(sqrt(M))                                           *
 *  @param	key    		integer represents address               *
 *  @param	data   		integer to be added                      *
 *  @return 1 if added 0 if not                                  *
 ****************************************************************/
int insertHash(int key,int data) {
    struct LinkedNode *curr;
    cmp++;
    if(!hashTable[key]){
        assign++; cpy++;
        hashTable[key] = malloc (sizeof(struct LinkedNode));
        hashTable[key]->data=data;
        return 1;
    } else {
        cmp++;
        if(hashTable[key]->data==data){
            return 0;
        }
        assign++;
        curr=hashTable[key];
        cmp++;
        while(curr->next){
            cmp++;
            if(curr->next->data==data){
                return 0;
            }
            assign++;            
            curr=curr->next;
            cmp++;
        }
        assign++;
        curr->next = malloc (sizeof(struct LinkedNode));
        cpy++;
        curr->next->data=data;
        return 1;
    }
}

/*****************************************************************
 *  Runs on the linked list frees every node.runs at O(sqrt(M))  *
 *  @param	node    		Array of linked lists                *
 ****************************************************************/
void freeList(struct LinkedNode* node){
    if(node==NULL) return;
    freeList(node->next);
    free(node);    
}

/*****************************************************************
 *  Runs on the hash table and frees every row.runs at O(sqrt(M))*
 *  @param	table			Array of linked lists                *
 ****************************************************************/
void freeHash ( struct LinkedNode ** table) {
    int i;
    for ( i = 0 ; i < HASHSIZE ; i++ )
        freeList ( table [ i ] );
}

/*****************************************************************
 *  Receives an array & its length, run on its elements activates*
 *  the hash function on them and inserts the value in the proper*
 *  place in the hash table using insertHash, runs at O(n).      *
 *  @param	arr				An array                             *
 *  @param	N				length of the array                  *
 *  @return number of insertion/unique numbers                   *
 ****************************************************************/
int makeHash ( int arr[], int N ) {
    int i, cnt=0;
    HASHSIZE = 1+sqrt ( CRANGE );
    hashTable = malloc ( HASHSIZE * sizeof ( struct LinkedNode* ) );
    assign+=3; cmp++;
    for ( i=0 ; i<N ; i++ ) {
        assign++;
        cnt += insertHash ( hashCode ( arr [ i ] ), arr [ i ] );
        assign++; cmp++;
    }
    freeHash ( hashTable );
    free ( hashTable );
    return cnt;
}