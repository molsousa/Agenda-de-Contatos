#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "agenda.h"

// Funcao para imprimir todos os elementos da lista
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void imprimir_tudo(Lista* l)
{
    Lista* aux = l;

    if(aux == NULL){
        printf("Nao ha usuarios cadastrados\n");
        system("pause");
        system("cls");
        return;
    }

    for(; aux != NULL; aux = aux->prox)
        imprimir_contato(aux);

    system("pause");
    system("cls");
}

// Funcao para buscar contato por nome
// Pre-condicao: lista criada e string do usuario
// Pos-condicao: nenhuma
void buscar_contato(Lista *l, char *nome)
{
    Lista *aux = l;

    if(aux == NULL){
        printf("Nao ha usuarios cadastrados\n");
        system("pause");
        system("cls");
        return;
    }

    for(aux = l; aux != NULL; aux = aux->prox){
        if( !strcmp(nome, aux->agend.nome) ){
            imprimir_contato(aux);
        }
    }
    system("pause");
    system("cls");
}

// Funcao para imprimir cada elemento da lista
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void inserir_dados(Agenda *x)
{
    printf("Insira o nome: ");
    fgets(x->nome, MAX, stdin);
    strtok(x->nome, "\n");

    printf("Insira o telefone: ");
    scanf("%d", &x->telefone);

    printf("Insira o dia de nascimento: ");
    scanf("%d", &x->aniv.dia);
    printf("Insira o mes de nascimento: ");
    scanf("%d", &x->aniv.mes);
    printf("Insira o ano de nascimento: ");
    scanf("%d", &x->aniv.ano);
}

// Imprimir determinado contato
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void imprimir_contato(Lista *l)
{
    printf("-------------------------------------------------\n");
    printf("\tNome: %s\n", l->agend.nome);
    printf("\tTelefone: %d\n", l->agend.telefone);
    printf("\tData de nascimento: %d/%d/%d\n", l->agend.aniv.dia, l->agend.aniv.mes, l->agend.aniv.ano);
    printf("-------------------------------------------------\n");
}

// Funcao para limpar entrada do teclado
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void limpar_buffer()
{
    char c;
    while(((c = getchar()) != '\n') && (c != EOF));
}

// Funcao para buscar usuario por letra
// Pre-condicao: lista criada e caractere do usuario
// Pos-condicao: nenhuma
void usuarios_letra(Lista *l, char c)
{
    Lista *aux = l;
    int i = 0;

    if(aux == NULL){
        printf("Nenhum usuario cadastrado\n");
        return;
    }

    for(; aux != NULL; aux = aux->prox){
        if(aux->agend.nome[0] == c){
            imprimir_contato(aux);
            i = 1;
        }
    }
    if(!i)
        printf("Nenhum usuario cadastrado com essa letra\n");

    system("pause");
    system("cls");
}

// Funcao para buscar usuario por mes de aniversario
// Pre-condicao: lista criada e inteiro do usuario
// Pos-condicao: nenhuma
void aniversariantes(Lista *l, int x)
{
    Lista *aux = l;
    int i = 0;

    if(aux == NULL){
        printf("Nenhum usuario cadastrado\n");
        return;
    }

    for(; aux != NULL; aux = aux->prox){
        if(aux->agend.aniv.mes == x){
            imprimir_contato(aux);
            i = 1;
        }
    }

    if(!i)
        printf("Nenhum usuario que faca aniversario nesse mes\n");

    system("pause");
    system("cls");
}

// Funcao para carregar agenda e armazenar na lista
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
Lista *carregar_agenda(FILE *f)
{
    Lista* novo = criar_lista();
    Agenda x;
    char c[1000], aux[MAX];
    int aux_telefone = 0;
    int aux_nascimento[3] = {0, 0, 0};

    x.aniv.dia = 0; x.aniv.mes = 0; x.aniv.ano = 0;
    x.telefone = 0;
    strcpy(x.nome, "NULL");
    strcpy(aux, "NULL");

    while(fgets(c, 1000, f) != NULL){
        sscanf(c, "Nome: %s", x.nome);
        sscanf(c, "Telefone: %d", &x.telefone);
        sscanf(c, "Data de nascimento: %d/%d/%d", &x.aniv.dia, &x.aniv.mes, &x.aniv.ano);

        if(strcmp(x.nome, aux) != 0){
            if(x.telefone != aux_telefone){
                if(x.aniv.dia != aux_nascimento[0] && x.aniv.mes != aux_nascimento[1] && x.aniv.ano != aux_nascimento[2]){
                    novo = lista_insere(novo, x);

                    sscanf(c, "Nome: %s", aux);
                    sscanf(c, "Telefone: %d", &aux_telefone);
                    sscanf(c, "Data de nascimento: %d/%d/%d", &aux_nascimento[0], &aux_nascimento[1], &aux_nascimento[2]);
                }
            }
        }
    }
    return novo;
}

// Funcao para armazenar lista num arquivo binario
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void armazenar_agenda(Lista *l, FILE *f, Lista *p)
{
    Lista* aux = l;

    for(; aux != NULL && aux != p; aux = aux->prox){
        fprintf(f, "---------------------------------------------\n");
        fprintf(f, "Nome: %s\n", aux->agend.nome);
        fprintf(f, "Telefone: %d\n", aux->agend.telefone);
        fprintf(f, "Data de nascimento: %d/%d/%d\n", aux->agend.aniv.dia, aux->agend.aniv.mes, aux->agend.aniv.ano);
        fprintf(f, "---------------------------------------------\n");
    }

    fclose(f);
}

// Funcao para reescrever agenda
// Pre-condicao: um ponteiro valido para lista valida
// Pos-condicao: variavel auxiliar do tipo Lista
Lista *reescrever_agenda(Lista *l, FILE *f)
{
    Lista *aux = l;
    f = fopen("Agenda.bin", "wb+");

    for(; aux != NULL; aux = aux->prox){
        fprintf(f, "---------------------------------------------\n");
        fprintf(f, "Nome: %s\n", aux->agend.nome);
        fprintf(f, "Telefone: %d\n", aux->agend.telefone);
        fprintf(f, "Data de nascimento: %d/%d/%d\n", aux->agend.aniv.dia, aux->agend.aniv.mes, aux->agend.aniv.ano);
        fprintf(f, "---------------------------------------------\n");
    }

    return l;
}

// Funcao para menu do usuario
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void menu()
{
    Lista *l = criar_lista();
    Lista *aux;
    Agenda x;
    char *nome = (char*) malloc(MAX * sizeof(char));
    int n;

    FILE *arquivo = fopen("Agenda.bin", "rb+");
    if(!arquivo){
        arquivo = fopen("Agenda.bin", "wb+");
    }

    l = carregar_agenda(arquivo);
    aux = l;

    do{
        printf("-----------------------Agenda-----------------------\n");
        printf("\t1 - Inserir usuario na agenda\n");
        printf("\t2 - Remover usuario da agenda\n");
        printf("\t3 - Procurar contato\n");
        printf("\t4 - Listar todos os contatos\n");
        printf("\t5 - Usuarios com a primeira letra do nome\n");
        printf("\t6 - Aniversariantes do mes\n");
        printf("\t0 - Sair\n");
        printf("----------------------------------------------------\n");
        printf("Insira: ");
        scanf("%d", &n);
        system("cls");
        limpar_buffer();

        switch(n){

        case 1:
            inserir_dados(&x);
            l = lista_insere(l, x);

            system("cls");
            break;

        case 2:
            printf("Insira o nome: ");
            fgets(nome, MAX, stdin);
            strtok(nome, "\n");

            l = excluir_elemento(l, nome);
            aux = reescrever_agenda(l, arquivo);

            printf("Usuario: %s removido\n", nome);
            system("pause");
            system("cls");
            break;

        case 3:
            printf("Insira o nome: ");
            fgets(nome, MAX, stdin);
            strtok(nome, "\n");

            buscar_contato(l, nome);
            break;

        case 4:
            imprimir_tudo(l);
            break;

        case 5:
            printf("Insira a letra: ");
            scanf("%c", &nome[0]);

            usuarios_letra(l, nome[0]);
            break;

        case 6:
            printf("Insira o mes: ");
            scanf("%d", &n);

            aniversariantes(l, n);
            break;

        case 0:
            printf("Obrigado!!\n");
            break;

        default:
            printf("Opcao invalida, tente novamente\n");
        }
    }while(n != 0);

    if(aux != l)
        armazenar_agenda(l, arquivo, aux);

    fclose(arquivo);
    free(nome);

    if(l != NULL)
        liberar_lista(l);
}
