#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noFila NoFila;
typedef struct noPilha NoPilha;
typedef struct noLista NoLista;

typedef struct pessoa{
    char nome[100];
    int idade;
}Pessoa;

struct noFila{
    Pessoa *passageiro;
    NoFila *prox;
    int idPassageiro;
};

struct noPilha{
    float peso;
    int idMala;
    int quant_mala;
    char cor[20];
    NoPilha *prox;
};

struct noLista{
    int checkin;
    NoFila *passageiro;
    NoPilha *mala;
    NoLista *prox,*ant;
};

void menu();

NoFila *cria_fila();
int fila_vazia(NoFila *f);
NoFila *insert_fila(NoFila *f,int id_passageiro);

NoPilha *cria_pilha();
int pilha_vazia(NoPilha *p);
NoPilha *insert_pilha(NoPilha *p,int id_mala);

NoLista *criar_l(NoLista *l);
NoLista *insert_l(NoLista *l,NoFila *f,NoPilha *p,int id);
void mostrar_lista(NoLista *l);

NoLista *busca_lfila(NoLista *l, NoFila *f, int id);
NoLista *busca_lpilha(NoLista *l, NoPilha *p, int id);

NoLista busca_sequencial (NoLista *l);
NoLista busca_sequencial2 (NoLista *l);

int *parabusca(NoLista *l, int id_passageiro, int left, int right);
int busca_binaria1 (NoLista *l, int *r, int id_passageiro);
int busca_binaria2 (NoLista *l, int *r, int id_passageiro);

NoLista bubblesort_menorqtdMcres (NoLista *l, int id_passageiro);
NoLista bubblesort_maiorqtdMCres(NoLista *l, int id_passageiro);
NoLista bubblesort_menorqtdMcres (NoLista *l, int id_passageiro);
NoLista bubblesort_maiorqtdMDecres(NoLista *l, int id_passageiro);
NoLista bubblesort_menorIDcres (NoLista *l, int id_passageiro);
NoLista bubblesort_maiorIDcres (NoLista *l, int id_passageiro);
NoLista bubblesort_menorIDdecres (NoLista *l, int id_passageiro);
NoLista bubblesort_maiorIDdecres (NoLista *l, int id_passageiro);

void quick_menormalascres(NoLista *l, int id_passageiro, int left, int right);
void quick_maiormalascres(NoLista *l, int id_passageiro, int left, int right);
void quick_menorIDdecres(NoLista *l, int id_passageiro, int left, int right);
void quick_maiorIDdecres(NoLista *l, int id_passageiro, int left, int right);
