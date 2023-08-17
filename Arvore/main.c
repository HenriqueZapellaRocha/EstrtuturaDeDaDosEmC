#include <stdio.h>
#include <stdlib.h>


struct nodo {
    int value;
    struct nodo *leftNode;
    struct nodo *rightNode;
};

typedef struct nodo Tree;

int main(void) {

    Tree *tree = malloc(sizeof(Tree));
    tree -> value =5;
    tree->leftNode=NULL;
    tree->rightNode=NULL;

    
    return 0;
}
