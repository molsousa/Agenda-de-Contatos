#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

// Funcao para criacao de lista encadeada
// Pre-condicao: ponteiro Lista criado
// Pos-condicao: nenhum
Lista *criar_lista()
{
    return NULL;
}

// Funcao para criacao de lista encadeada
// Pre-condicao: ponteiro Lista criado
// Pos-condicao: nenhum
Lista *lista_insere(Lista *l, Agenda x)
{
    Lista *aux;

    aux = (Lista*) malloc(sizeof(Lista));

    aux->agend = x;
    aux->prox = l;

    return aux;
}

// Funcao para excluir elemento da lista
// Pre-condicao: lista criada
// Pos-condicao: nenhuma
Lista *excluir_elemento(Lista *l, char *x)
{
    Lista *anterior = NULL;
    Lista *aux = l;

    // loop ocorre ate que aux seja nulo e encontre um nome igual
    while(aux != NULL && (strcmp(aux->agend.nome, x)) != 0){
        anterior = aux;
        aux = aux->prox;
    }

    // se for nulo, retorna a lista
    if(aux == NULL){
        printf("Usuario nao encontrado\n\n");
        system("pause");
        system("cls");
        return l;
    }

    // caso o nome esteja no inicio da lista
    if(aux == l){
        l = aux->prox;
    }

    // caso o nome esteja no final ou no meio da lista
    // o valor anterior a aux recebe o valor posterior de aux
    // 11-> - *13->* - 15-> | 11 -> - 15->
    else
        anterior->prox = aux->prox;

    free(aux);

    return l;
}

// Funcao para liberar lista encadeada
// Pre-condicao: lista criada
// Pos-condicao: nenhuma
void liberar_lista(Lista* l)
{
    Lista *aux = l;
    Lista *t;

    // percorre a lista ate que seja nula (final da lista)
    while(aux->prox != NULL){
        t = aux->prox;
        free(aux);
        aux = t;
    }

    free(aux);
}
