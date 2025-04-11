#ifndef LISTAS_H_
#define LISTAS_H_
#define MAX 26

typedef struct lista Lista;
typedef struct agenda Agenda;

// Estrutura para dia de nascimento
typedef struct aniversario{
    int dia;
    int mes;
    int ano;
}Aniversario;

// Estrutura para agenda
struct agenda{
    char nome[MAX];
    int telefone;
    Aniversario aniv;
};

// Estrutura de lista dinamica
struct lista{
    Agenda agend;
    struct lista *prox;
};

// Funcao para criacao de lista encadeada
// Pre-condicao: ponteiro Lista criado
// Pos-condicao: nenhum
Lista *criar_lista();

// Funcao para inserir na lista
// Pre-condicao: lista criada
// Pos-condicao: retorna um ponteiro do tipo Lista
Lista *lista_insere(Lista *l, Agenda x);

// Funcao para excluir elemento da lista
// Pre-condicao: lista criada
// Pos-condicao: nenhuma
Lista *excluir_elemento(Lista *l, char *x);

// Funcao para liberar lista encadeada
// Pre-condicao: lista criada
// Pos-condicao: nenhuma
void liberar_lista(Lista* l);

#endif // LISTAS_H_
