#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int bstcnt=0;

struct Tnode {
    int data;
    struct Tnode *left, *right;
};

struct Tnode* root;
 
/*****************************************************************
 *  Recieves data and creates node. runs at O(1)                 *
 *  @param	data   		integer to be added                      *
 *  @return node with data                                       *
 ****************************************************************/
struct Tnode* newNode(int data){
    struct Tnode* temp = (struct Tnode*) malloc (sizeof(struct Tnode));
    assign+=4;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
/*****************************************************************
 *  Recieves a Tnode and data, if isnt in tree adds data as node *
 *  according to Binary search tree. runs at O(log(M))           *
 *  @param	node    	current tree node                        *
 *  @param	data   		integer to be added                      *
 *  @return 1 if added 0 if not                                  *
 ****************************************************************/
struct Tnode* insert(struct Tnode* node, int data){
    /* If the tree is empty, return a new node */
    cmp++;
    if (node == NULL){
        assign++;
        bstcnt++;
        cpy++;
        return newNode(data);
    }
    cmp++;
    if (data == node->data){
        return node;
    }
    cmp++;
    if (data < node->data) {
        assign++;
        node->left = insert(node->left, data);
    } else {
        assign++;
        node->right = insert(node->right, data);
    }
    return node;
}

/*****************************************************************
 *  Runs on the BST frees every node. runs at O(log(M))          *
 *  @param	node    		Tree Node                            *
 ****************************************************************/
void freeTree(struct Tnode* node){
    if (node==NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

/*****************************************************************
 *  Receives an array & its length, run on its elements inserts  *
 *  to the biunary search tree, returns number of insertions.    *
 *  runs at O(N).                                                *
 *  @param	arr				An array                             *
 *  @param	N				length of the array                  *
 *  @return number of insertion/unique numbers                   *
 ****************************************************************/
int makeBST(int *arr, int N) {
    int i=0;
    assign++; cmp++;
    for ( i=0 ; i<N ; i++ ){
        root = insert(root,arr[i]);
        assign++; cmp++;
    }
    freeTree(root);
    return bstcnt;
}