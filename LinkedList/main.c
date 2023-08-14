#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    int numero;
    struct LinkedList *proximo;
};

typedef struct LinkedList list;

list *primeiroNodo;

void add(int x) {
    
    list *lista = (list*) malloc(sizeof(list));
    lista -> numero = x;
    lista -> proximo = primeiroNodo;
    primeiroNodo = lista;
}

void exibeNaTelaLista() {

    list *aux = primeiroNodo;
    while (aux != NULL) {
        printf("-> %d ", aux->numero);
        aux = aux -> proximo;
    }
  
    
}


int main(){

    add(1);
    add(2);
    add(3);
    add(4);
    add(5);

    exibeNaTelaLista();
    
}