#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int bstcnt=0;

struct bnode {
    int key;
    struct bnode *left, *right;
};

struct bnode* root;
 
// A utility function to create a new BST node
struct bnode* newNode(int item){
    struct bnode* temp = (struct bnode*) malloc (sizeof(struct bnode));
    assign+=4;
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new node with given key in BST */
struct bnode* insert(struct bnode* node, int key){
    /* If the tree is empty, return a new node */
    cmp++;
    if (node == NULL){
        assign++;
        bstcnt++;
        cpy++;
        return newNode(key);
    }
    cmp++;
    if (key < node->key){
        node->left = insert(node->left, key);
        return node;
    }
    cmp++;
    if (key > node->key){
        node->right = insert(node->right, key);
        return node;
    }
    return NULL;
}

void freeTree(struct bnode* node){
    if (node==NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

void inborder(struct bnode* trav)
{
    if (trav == NULL)
        return;
    inborder(trav->left);
    printf("%d ", trav->key);
    inborder(trav->right);
}

int makeBST(int *arr, int N) {
    int i;
    assign++; cmp++;
    for ( i=0 ; i<N ; i++ ){
        root = insert(root,arr[i]);
        assign++; cmp++;
    }
    inborder(root);
    freeTree(root);
    return bstcnt;
}