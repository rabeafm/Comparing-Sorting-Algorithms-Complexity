#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

struct Node
{
    int data;
    struct Node *next;
};

struct Node **hashArray; 

int hashCode(int k) {
   return (int) HASHSIZE * fmodf((sqrt(5)-1)*k,1);
}

int insertHash(int key,int data) {
    struct Node *curr;
    cmp++;
    if(!hashArray[key]){
        assign++; cpy++;
        hashArray[key] = malloc (sizeof(struct Node));
        hashArray[key]->data=data;
        return 1;
    } else {
        cmp++;
        if(hashArray[key]->data==data){
            return 0;
        }
        assign++;
        curr=hashArray[key];
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
        curr->next = malloc (sizeof(struct Node));
        cpy++;
        curr->next->data=data;
        return 1;
    }
}

void freeList(struct Node* n){
    if(n==NULL) return;
    freeList(n->next);
    free(n);    
}

void freeHash(struct Node **table){
    int i;
    for(i=0;i<HASHSIZE;i++)
        freeList(table[i]);
    free(table);
}

int makehash(int *arr, int N) {
    int i,cnt=0;
    HASHSIZE=1+sqrt(N);
    hashArray = malloc (HASHSIZE * sizeof(struct Node*));
    assign+=3; cmp++;
    for ( i=0 ; i<N ; i++ ){
        assign++;
        cnt+=insertHash(hashCode(arr[i]),arr[i]);
        assign++; cmp++;
    }
    freeHash(hashArray);
    return cnt;
}