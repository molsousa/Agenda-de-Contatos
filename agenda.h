#ifndef AGENDA_H_
#define AGENDA_H_

typedef struct lista Lista;
typedef struct agenda Agenda;

// Funcao para imprimir todos os elementos da lista
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void imprimir_tudo(Lista* l);

// Funcao para buscar contato por nome
// Pre-condicao: lista criada e string do usuario
// Pos-condicao: nenhuma
void buscar_contato(Lista *l, char *nome);

// Funcao para imprimir cada elemento da lista
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void inserir_dados(Agenda *x);

// Imprimir determinado contato
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void imprimir_contato(Lista *l);

// Funcao para limpar entrada do teclado
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void limpar_buffer();

// Funcao para buscar usuario por letra
// Pre-condicao: lista criada e caractere do usuario
// Pos-condicao: nenhuma
void usuarios_letra(Lista *l, char c);

// Funcao para buscar usuario por mes de aniversario
// Pre-condicao: lista criada e inteiro do usuario
// Pos-condicao: nenhuma
void aniversariantes(Lista *l, int x);

// Funcao para carregar agenda e armazenar na lista
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
Lista *carregar_agenda(FILE *f);

// Funcao para armazenar lista num arquivo binario
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void armazenar_agenda(Lista *l, FILE *f, Lista *p);

// Funcao para reescrever agenda
// Pre-condicao: um ponteiro valido para lista valida
// Pos-condicao: variavel auxiliar do tipo Lista
Lista *reescrever_agenda(Lista *l, FILE *f);

// Funcao para menu do usuario
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void menu();


#endif // AGENDA_H_
