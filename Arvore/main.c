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

Tree * searchByValueReturningNode(int value, Tree *node, Tree *reference) {

    // verify if the actual node is identical value than we are comparing
    if (node != NULL && ((node->leftNode != NULL && node->leftNode->value == value) || node->rightNode != NULL && node->rightNode->value == value))  {
       
        reference = node;
        return reference;
        
    }
    // if the value we are searching is smaller than the node we have, so we make a recursive call passing the left children
    if (value < node->value && node->leftNode != NULL) {
        return searchByValueReturningNode(value, node->leftNode, reference);
    // if the value we are searching is bigger than the node we have, so we make a recursive call passing the right children
    } else if (value > node->value && node->rightNode != NULL) {
        return searchByValueReturningNode(value, node->rightNode, reference);
    }

return NULL;

 }

// This function demonstrates a case of node removal, where it returns the rightmost node from the left subtree as compared to the receiving node
 Tree * fatherFromTheMoreBiggerNodeFromLeftSubTree(Tree *node, Tree *reference) {

    if(node->rightNode->rightNode == NULL ) {
        reference = node;
        return reference;
    }
    else {
        return fatherFromTheMoreBiggerNodeFromLeftSubTree(node->rightNode , reference);
    }

 }

 bool removeNode(int value, Tree *node) {


// substituir pelo maior no da arvore da esquerda 

    Tree *search = searchByValueReturningNode(value, node, NULL);

    //if the node to be removed is on the left of the parent and it doesn't have children
    if((search->leftNode != NULL) && search->leftNode->value == value && search->leftNode->leftNode == NULL && search->leftNode->rightNode == NULL) {
        free(search->leftNode);
        search->leftNode = NULL;
        nElemntos--;
        return true;
    } 
     //if the node to be removed is on the left of the parent and it doesn't have children
    if((search->rightNode != NULL) && search->rightNode->value == value && search->rightNode->leftNode == NULL && search->rightNode->rightNode == NULL) {
        free(search->rightNode);
        search->rightNode = NULL;
        nElemntos--;
        return true;
    } 
    // if the node to be removed is on the right and it has any child
    if((search->leftNode != NULL) && search->leftNode->value == value && (search->leftNode->leftNode != NULL || search->leftNode->rightNode != NULL)) { 
        //if the node to be removed has only one child, and it is located on the left
        if(search->leftNode->leftNode != NULL && search->leftNode->rightNode == NULL) {
            search->leftNode = search->leftNode->leftNode;
            free(search->leftNode->leftNode);
            search->leftNode->leftNode = NULL;
            nElemntos--;
            return true;
        }
         // if the node have two childrens
        if(search->leftNode->leftNode != NULL && search->leftNode->rightNode != NULL) {
            Tree *theMost = fatherFromTheMoreBiggerNodeFromLeftSubTree(search->rightNode->leftNode, NULL);
            search->leftNode->value = theMost->rightNode->value;
            free(theMost->rightNode);
            theMost->rightNode = NULL;
        }
         //if the node to be removed has only one child, and it is located on the right
        if(search->leftNode->leftNode == NULL && search->leftNode->rightNode != NULL) {
            search->leftNode = search->leftNode->rightNode;
            free(search->leftNode->rightNode);
            search->leftNode->rightNode = NULL;
            nElemntos--;
            return true;

        }
    }
    // if the node to be removed is on the right and it has any child
    if((search->rightNode != NULL) && search->rightNode->value == value && (search->rightNode->leftNode != NULL || search->rightNode->rightNode != NULL)) { 
        //if the node to be removed has only one child, and it is located on the left
        if(search->rightNode->leftNode != NULL && search->rightNode->rightNode == NULL) {
            search->rightNode = search->rightNode->leftNode;
            free(search->rightNode->leftNode);
            search->rightNode->leftNode = NULL;
            nElemntos--;
            return true;
        }
        // if the node have two childrens
        if(search->rightNode->leftNode != NULL && search->rightNode->rightNode != NULL) {
            Tree *theMost = fatherFromTheMoreBiggerNodeFromLeftSubTree(search->rightNode->leftNode, NULL);
            search->rightNode->value = theMost->rightNode->value;
            free(theMost->rightNode);
            theMost->rightNode = NULL;
        }
        //if the node to be removed has only one child, and it is located on the right
        if(search->rightNode->leftNode == NULL && search->rightNode->rightNode != NULL) {
            search->rightNode = search->rightNode->rightNode;
            free(search->rightNode->rightNode);
            search->rightNode->rightNode = NULL;
            nElemntos--;
            return true;
        }
    }
  
  
    return false;
 }      



int main() {


    add(12, root);
    add(17, root);
    add(13, root);
    add(14, root);
    add(24,root);
    add(15,root);
    removeNode(17,root);

  

    return 0;
}
