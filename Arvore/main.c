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


bool add(int value, Tree *node) {

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
    if(node->value > value) {
    // if the node dont have a left child    
    if (node->leftNode == NULL){
        node->leftNode=malloc(sizeof(Tree));
        node->leftNode->value =value;
        node->leftNode->leftNode=NULL;
        node->leftNode->rightNode=NULL;
        nElemntos++;
        return true;  
    // if the node have a left child. recursive call passing the left node  
    } else {
    return add(value, node->leftNode);
    }  
    // if the value is bigger than the node
    } else if(node->value < value) {
        // if the node dont have a right child    
        if (node->rightNode == NULL){
        node->rightNode=malloc(sizeof(Tree));
        node->rightNode->value =value;
        node->rightNode->leftNode=NULL;
        node->rightNode->rightNode=NULL;
        nElemntos++;   
        return true; 
    // if the node have a right child. recursive call passing the right node 
    } else {
    return add(value, node->rightNode);
    }  
    }
    
    return false;
    }



bool searchByValue(int value, Tree *node) {

    // verify if the actual node is identical value than we are comparing
    if (node != NULL && node->value == value) {
        return true;
    }
    // if the value we are searching is smaller than the node we have, so we make a recursive call passing the left children
    if (value < node->value && node->leftNode != NULL) {
        return searchByValue(value, node->leftNode);
    // if the value we are searching is bigger than the node we have, so we make a recursive call passing the right children
    } else if (value > node->value && node->rightNode != NULL) {
        return searchByValue(value, node->rightNode);
    }


return false;

 }

Tree searchByValueReturningNode(int value, Tree *node) {

    // verify if the actual node is identical value than we are comparing
    if (node != NULL && node->value == value) {
        return *node;
    }
    // if the value we are searching is smaller than the node we have, so we make a recursive call passing the left children
    if (value < node->value && node->leftNode != NULL) {
        return searchByValueReturningNode(value, node->leftNode);
    // if the value we are searching is bigger than the node we have, so we make a recursive call passing the right children
    } else if (value > node->value && node->rightNode != NULL) {
        return searchByValueReturningNode(value, node->rightNode);
    }

 }

 bool removeNode(int value, Tree *node) {



    if((node->value != NULL) && (node->value == value) && (node->leftNode == NULL) && (node->rightNode == NULL)) {
        node = NULL;
        nElemntos--;
        return true;
    } 
     // if the value we are searching is smaller than the node we have, so we make a recursive call passing the left children
    if (value < node->value && node->leftNode != NULL) {
        return remmoveNode(value, node->leftNode);
    // if the value we are searching is bigger than the node we have, so we make a recursive call passing the right children
    } else if (value > node->value && node->rightNode != NULL) {
        return removeNode(value, node->rightNode);
    }


 }      



int main(void) {


   add(9,root);
   add(4, root);
   add(3, root);
   add(13, root);
   add(14, root);
   add(10, root);
   add(20,root);
  
    printf("%d   %d   %d  //  %d   %d    %d\n", root->value, root->leftNode->value, root->leftNode->leftNode->value, root->rightNode->value, root->rightNode->rightNode->value, root->rightNode->leftNode->value);
    removeNode(3, root);
     printf("%d   %d   %d  //  %d   %d    %d\n", root->value, root->leftNode->value, root->leftNode->leftNode->value, root->rightNode->value, root->rightNode->rightNode->value, root->rightNode->leftNode->value);
    
    return 0;
}
