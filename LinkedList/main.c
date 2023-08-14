#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// funcao que remove um nodo da linkedlist por o valor contido no espaco de dados
void removeByNumber(int numero) {

    list *aux = primeiroNodo;
    list *anterior = NULL;
    
    while(aux != NULL) {
        // testa se o nodo atual tem o mesmo valor a ser buscado
        if(aux -> numero == numero) {
            // caso o primeiro nodo seja o a ser retirado
            if(aux == primeiroNodo) {
            // primeiro nodo se torna o proximo nodo 
            primeiroNodo = aux->proximo;
            // "mata" o nodo a ser removido da memoria
            aux = NULL;
            // caso o nodo a ser removido seja o ultimo
            } else if (aux == UltimoNodo) {
            // retira os ponteiros do nodo a ser removido 
            anterior->proximo = aux->proximo;
            // ultimo nodo se torna o anterior ao que foi retirado
            UltimoNodo = anterior;
            // "mata" o nodo a ser removido da memoria
            aux = NULL;
            } else {
            // retira os ponteiros do nodo a ser removido 
            anterior->proximo = aux->proximo;
            // "mata" o nodo a ser removido da memoria
            aux = NULL;
            }
        } else{
            // caso o valor do nodo nao seja igual, anda para frente e armazena o anterior
            anterior = aux;
            aux = aux->proximo;
        }
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
    printf("\n");
    removeByNumber(5);
    exibeNaTelaLista();
    
}