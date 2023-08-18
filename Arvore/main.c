#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct nodo {
    int value;
    struct nodo *leftNode;
    struct nodo *rightNode;
};

typedef struct nodo Tree;

int nElemntos=0;
Tree *root;


bool add(int value, Tree node) {

    // case the root dont exist
    if (root == NULL) {
        root=malloc(sizeof(Tree));
        root->value =value;
        root->leftNode=NULL;
        root->rightNode=NULL;
        nElemntos++;
        return true;
    }

    // if the value is small than the node
    if(node.value > value) {
    // if the node dont have a left child    
    if (node.leftNode == NULL){
        node.leftNode=malloc(sizeof(Tree));
        node.leftNode->value =value;
        node.leftNode->leftNode=NULL;
        node.leftNode->rightNode=NULL;
        nElemntos++;
        return true;  
    // if the node have a left child. recursive call passing the left node  
    } else {
        add(value, *node.leftNode);
    }  
    // if the value is bigger than the node
    } else if(node.value < value) {
        // if the node dont have a right child    
        if (node.leftNode == NULL){
        node.rightNode=malloc(sizeof(Tree));
        node.rightNode->value =value;
        node.rightNode->leftNode=NULL;
        node.rightNode->rightNode=NULL;
        nElemntos++;   
        return true; 
    // if the node have a right child. recursive call passing the right node 
    } else {
        add(value, *node.rightNode);
    }  
    }

    return false;
    }



int main(void) {

   

    
    return 0;
}
