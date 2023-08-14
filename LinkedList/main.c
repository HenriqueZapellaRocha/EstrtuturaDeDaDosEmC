#include <stdio.h>
#include <stdlib.h>

// estrutura para LinkedList
struct LinkedList
{
    int numero;
    struct LinkedList *proximo;
};

typedef struct LinkedList list;

// referencia para o primeiro nodo
list *primeiroNodo;
list *UltimoNodo;


// funcao que adiciona novos nodoas a linkedlist
void add(int x) {
    
    list *lista = (list*) malloc(sizeof(list));
    lista -> numero = x;
    if(primeiroNodo == NULL) {
        primeiroNodo = lista;
        UltimoNodo = lista;
    } else {
        UltimoNodo->proximo = lista;
        UltimoNodo = lista;
    }
    
}

// funcao que escreve no terminal os elementos da lista encadeada
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