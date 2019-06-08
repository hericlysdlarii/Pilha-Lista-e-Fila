#include "Biblioteca.h"

void menu(){
    printf("                    MENU                  \n");
    printf("1 - Check-in\n");
    printf("2 - Lista de Embarque\n");
    printf("3 - Busca Sequencial por ID\n");
    printf("4 - Busca Sequencial por nome na lista de Embarque\n");
    printf("5 - Busca Binaria por maior quantidade de malas\n");
    printf("6 - Busca Binaria por menor quantidade de malas\n");
    printf("7 - Menor Quantidade de Malas (CRESCENTE)\n");
    printf("8 - Maior Quantidade de Malas (CRESCENTE)\n");
    printf("9 - Menor Quantidade de Malas (DECRESCENTE)\n");
    printf("10 - Maior Quantidade de Malas (DECRESCENTE)\n");
    printf("11 - Menor id do Passageiro (CRESCENTE)\n");
    printf("12 - Maior id do Passageiro (CRESCENTE)\n");
    printf("13 - Menor id do Passageiro (DECRESCENTE)\n");
    printf("14 - Maior id do Passageiro (DECRESCENTE)\n");
    printf("15 - Menor Quantidade de Malas (CRESCENTE)\n");
    printf("16 - Maior Quantidade de Malas (CRESCENTE)\n");
    printf("17 - Menor Quantidade de Malas (DECRESCENTE)\n");
    printf("18 - Maior Quantidade de Malas (DECRESCENTE)\n");
    printf("19 - Menor id do Passageiro (CRESCENTE)\n");
    printf("20 - Maior id do Passageiro (CRESCENTE)\n");
    printf("21 - Menor id do Passageiro (DECRESCENTE)\n");
    printf("22 - Maior id do Passageiro (DECRESCENTE)\n");
    printf("23 - SAIR\n");
    printf("Entre com uma opçao: ");
}

NoFila *cria_fila(){
    return NULL;
}

int fila_vazia(NoFila *f){
if(f==NULL)
    return 1;
else
    return 0;
}

NoFila *insert_fila(NoFila *f,int id_passageiro){
    NoFila *teste = f;
    NoFila *novo = (NoFila*)malloc(sizeof(NoFila));
    novo->passageiro=(Pessoa*)malloc(sizeof(Pessoa));
        printf("Nome: ");
        scanf("%s",novo->passageiro->nome);
        printf("Idade: ");
        scanf("%d",&novo->passageiro->idade);
        novo->idPassageiro = id_passageiro;
        printf("id do passageiro: %d\n",novo->idPassageiro);

        novo->prox = NULL;
    if(fila_vazia(f)==1){
        return novo;
    }else{
        while(teste->prox != NULL){
            teste = teste->prox;
        }
        teste->prox=novo;
    }

return f;
}

NoPilha *cria_pilha(){
    return NULL;
}

int pilha_vazia(NoPilha *p){
    if(p==NULL){
        return 1;
    }else{
        return 0;
    }
}

NoPilha *insert_pilha(NoPilha *p,int id_mala){
    NoPilha *novo=(NoPilha*)malloc(sizeof(NoPilha));
    printf("CADASTRO DE MALAS\n");
    printf("Peso: ");
    scanf("%f",&novo->peso);
    printf("Quantidade de malas: ");
    scanf("%d",&novo->quant_mala);
    novo->idMala = id_mala;
    printf("Cor: ");
    scanf("%s",novo->cor);
    printf("id mala: %d\n",novo->idMala);
    novo->prox=p;
    p=novo;
    getchar();
    system("clear");
    return p;
}

NoLista *criar_l(NoLista *l){
    return NULL;
}

NoLista *insert_l(NoLista *l,NoFila *f,NoPilha *p,int id){
    NoLista *teste = l;

    if(teste==NULL){
        NoLista *novo;
        novo=(NoLista*)malloc(sizeof(NoLista));

            novo->checkin= id;
            novo->mala = p;
            novo->passageiro = f;
            return novo;

      }else{
        while(teste->prox != NULL){
            teste=teste->prox;
        }
        NoLista *novo;
        novo=(NoLista*)malloc(sizeof(NoLista));
        novo->prox=NULL;
        novo->checkin = id;
        novo->mala = busca_lpilha(l, p, id);
        novo->passageiro = busca_lfila(l, f, id);
        novo->ant=teste;
        teste->prox=novo;
        return l;
    }

}

NoLista *busca_lfila(NoLista *l, NoFila *f, int id){
     NoFila *p;
        for(p=f;p!=NULL;p=p->prox){
        if (p->idPassageiro == id){
            return p;
        }
    }
}

NoLista *busca_lpilha(NoLista *l, NoPilha *p, int id){
    NoPilha *j;
    for(j=p; j!=NULL; j=j->prox){
        if(j->idMala == id){
            return j;
        }
    }
}

void mostrar_lista(NoLista *l){
    NoLista *d;
    int x=1;
        printf("\n");
        printf(":::::::::::::::::::::::::::::::\n");
        for(d=l;d!=NULL;d=d->prox){
            printf("Nome: %s\n", d->passageiro->passageiro->nome);
            printf("Idade: %d\n", d->passageiro->passageiro->idade);
            printf("Id Passageiro: %d\n\n", d->passageiro->idPassageiro);
            printf("Peso: %.2f\n",d->mala->peso);
            printf("Quantidade: %d\n",d->mala->quant_mala);
            printf("Id Mala: %d\n",d->mala->idMala);
            printf("cor: %s\n",d->mala->cor);
            printf(":::::::::::::::::::::::::::::::\n");
            printf("\n");
            x++;
        }
    getchar();
    system("clear");
}

NoLista busca_sequencial (NoLista *l){
    NoLista *d;
    int idbusca;
    printf("Informe o ID do passageiro a ser buscado: ");
    scanf("%d",&idbusca);
    printf("\n");

    for(d=l; d!=NULL; d=d->prox){
            if(d->passageiro->idPassageiro == idbusca){
                printf(":::::::::::::::::::::::::::::::\n");
                printf("Nome: %s\n", d->passageiro->passageiro->nome);
                printf("Idade: %d\n", d->passageiro->passageiro->idade);
                printf("Id Passageiro: %d\n\n", d->passageiro->idPassageiro);
                printf("Peso: %.2f\n",d->mala->peso);
                printf("Quantidade: %d\n",d->mala->quant_mala);
                printf("Id Mala: %d\n",d->mala->idMala);
                printf("cor: %s\n",d->mala->cor);
                printf(":::::::::::::::::::::::::::::::\n");
                printf("\n");
                return;
            }

    }

}

NoLista busca_sequencial2 (NoLista *l){
    NoLista *d;
    char nome[20];
    printf("Informe o nome do passageiro a ser buscado: ");
    scanf("%s",nome);
    printf("\n");

    for(d=l; d!=NULL; d=d->prox){
            if(strcmp(d->passageiro->passageiro->nome,nome)==0){
                printf("Nome: %s\n", d->passageiro->passageiro->nome);
                printf("Idade: %d\n", d->passageiro->passageiro->idade);
                printf("Id Passageiro: %d\n\n", d->passageiro->idPassageiro);
                printf("Peso: %.2f\n",d->mala->peso);
                printf("Quantidade: %d\n",d->mala->quant_mala);
                printf("Id Mala: %d\n",d->mala->idMala);
                printf("cor: %s\n",d->mala->cor);
                printf(":::::::::::::::::::::::::::::::\n");
                printf("\n");
                system("pause");
                return;
            }
        }
}


//busca binaria
int *parabusca(NoLista *l, int id_passageiro, int left, int right){
    int *v, i, j, x, y, a=0;
    NoLista *g;
    int n;
    v=(int*)malloc(sizeof(int)*id_passageiro);
    for(g=l;  g!=NULL; g=g->prox){
        v[a]=g->mala->quant_mala;
        a++;
    }

    i=left;
    j=right;
    n= v[(left+right)/2];
    while(i<=j){
        while(v[i] < n && i <right){
            i++;
        }
        while(v[j] > n && j > left){
            j--;
        }
        if(i <= j){
            y=v[i];
            v[i]=v[j];
            v[j]= y;
            i++;
            j--;
        }
    }
    if (j > i){
        quick_menormalascres(l, id_passageiro, left, j);
    }
    if (i < j){
        quick_menormalascres(x, id_passageiro, i, right);
    }

return v;
}

int busca_binaria1 (NoLista *l, int *v, int id_passageiro){
    NoLista *d;
    int left=0, right=id_passageiro, meio;

        while (left <= right){
            meio = ((left+right)/2);
                if(v[id_passageiro-1] == v[meio]){
                    return v[id_passageiro -1];
                }
                if(v[id_passageiro-1] > v[meio]){
                    right = meio+1;
                }else{
                    left= meio-1;
                }
        }
    return -1;
}

int busca_binaria2 (NoLista *l, int *v, int id_passageiro){
    NoLista *d;
    int left=0, right=id_passageiro, meio;

        while (left <= right){
            meio = ((left+right)/2);
                if(v[0] == v[meio]){
                    return v[meio];
                }
                if(v[0] < v[meio]){
                    right = meio;
                }else{
                    left= meio;
                }
        }
    return -1;
}

NoLista bubblesort_menorqtdMcres (NoLista *l, int id_passageiro){
    int *vetor, a=0, b=0, aux=0;
    NoLista *z;
    vetor=(int*)malloc(sizeof(int)*id_passageiro);

    for (z=l; z!=NULL; z=z->prox){
        vetor[a]=z->mala->quant_mala;
        a++;
    }
    for(a=0;a<id_passageiro;a++){
        for (b=a+1;b<id_passageiro;b++){
            if(vetor[a]>vetor[b]){
                aux=vetor[a];
                vetor[a]=vetor[b];
                vetor[b]=aux;
            }
        }
    }
    printf("Ordenacao concluida com sucesso!\n");
    printf("As Malas estao empilhadas em ordem crescente!\n");

    for (int j=0; j<id_passageiro; j++){
        printf("%d a embarcar tem %d mala(s)\n", j+1, vetor[j]);
        printf("\n");
    }
}

NoLista bubblesort_maiorqtdMCres(NoLista *l, int id_passageiro){
    int *vetor, a=0, b=0, aux=0;
    NoLista *z;
    vetor=(int*)malloc(sizeof(int)*id_passageiro);

    for (z=l; z!=NULL; z=z->prox){
        vetor[a]=z->mala->quant_mala;
        a++;
    }
    for(a=0;a<id_passageiro;a++){
        for (b=a+1;b<id_passageiro;b++){
            if(vetor[a]>vetor[b]){
                aux=vetor[a];
                vetor[a]=vetor[b];
                vetor[b]=aux;
            }
        }
    }
    printf("Ordenacao concluida com sucesso!\n");
    printf("As Malas estao empilhadas em ordem crescente!\n");

    int p, r=1;
     for (p=id_passageiro; p>0; p--){
        printf("%d a embarcar tem %d mala(s)\n", r, vetor[p-1]);
        printf("\n");
        r++;
    }
}

NoLista bubblesort_menorqtdMdecres (NoLista *l, int id_passageiro){
    int *vetor, a=0, b=0, aux=0;
    NoLista *z;
    vetor=(int*)malloc(sizeof(int)*id_passageiro);

    for (z=l; z!=NULL; z=z->prox){
        vetor[a]=z->mala->quant_mala;
        a++;
    }
    for(a=0;a<id_passageiro;a++){
        for (b=a+1;b<id_passageiro;b++){
            if(vetor[a]<vetor[b]){
                aux=vetor[a];
                vetor[a]=vetor[b];
                vetor[b]=aux;
            }
        }
    }
    printf("Ordenacao concluida com sucesso!\n");
    printf("As Malas estao empilhadas em ordem decrescente!\n");
    int p;
       for (p=0; p<id_passageiro; p++){
        printf("%d a embarcar tem %d mala(s)\n", p, vetor[p]);
        printf("\n");
       }
}

NoLista bubblesort_maiorqtdMDecres(NoLista *l, int id_passageiro){
    int *vetor, a=0, b=0, aux=0;
    NoLista *z;
    vetor=(int*)malloc(sizeof(int)*id_passageiro);

    for (z=l; z!=NULL; z=z->prox){
        vetor[a]=z->mala->quant_mala;
        a++;
    }
    for(a=0;a<id_passageiro;a++){
        for (b=a+1;b<id_passageiro;b++){
            if(vetor[a]>vetor[b]){
                aux=vetor[a];
                vetor[a]=vetor[b];
                vetor[b]=aux;
            }
        }
    }
    printf("Ordenacao concluida com sucesso!\n");
    printf("As Malas estao empilhadas em ordem decrescente!\n");

    int p, r=1;
     for (p=id_passageiro; p>0; p--){
        printf("%d a embarcar tem %d mala(s)\n", r, vetor[p-1]);
        printf("\n");
        r++;
    }
}

NoLista bubblesort_menorIDcres (NoLista *l, int id_passageiro){
    int *vetor, a=0, b=0, aux=0;
    NoLista *z;
    vetor=(int*)malloc(sizeof(int)*id_passageiro);

    for (z=l; z!=NULL; z=z->prox){
        vetor[a]=z->passageiro->idPassageiro;
        a++;
    }
    for(a=0;a<id_passageiro;a++){
        for (b=a+1;b<id_passageiro;b++){
            if(vetor[a]<vetor[b]){
                aux=vetor[a];
                vetor[a]=vetor[b];
                vetor[b]=aux;
            }
        }
    }
    printf("Ordenacao concluida com sucesso!\n");
    printf("Os passageios estão em ordem crescente!\n");
    int p, r=1;
     for (p=id_passageiro; p>0; p--){
        printf("%d a embarcar tem id %d\n",r, vetor[p-1]);
        printf("\n");
        r++;
    }
}

NoLista bubblesort_maiorIDcres (NoLista *l, int id_passageiro){
    int *vetor, a=0, b=0, aux=0;
    NoLista *z;
    vetor=(int*)malloc(sizeof(int)*id_passageiro);

    for (z=l; z!=NULL; z=z->prox){
        vetor[a]=z->passageiro->idPassageiro;
        a++;
    }
    for(a=0;a<id_passageiro;a++){
        for (b=a+1;b<id_passageiro;b++){
            if(vetor[a]<vetor[b]){
                aux=vetor[a];
                vetor[a]=vetor[b];
                vetor[b]=aux;
            }
        }
    }
    printf("Ordenacao concluida com sucesso!\n");
    printf("Os passageios estão em ordem crescente!\n");
    int p, x=0;
       for (p=0; p<id_passageiro; p++){
        printf("%d a embarcar tem ID %d\n", p+1, vetor[x]);
        printf("\n");
            x++;
       }
}

NoLista bubblesort_maiorIDdecres (NoLista *l, int id_passageiro){
    int *vetor, a=0, b=0, aux=0;
    NoLista *z;
    vetor=(int*)malloc(sizeof(int)*id_passageiro);

    for (z=l; z!=NULL; z=z->prox){
        vetor[a]=z->passageiro->idPassageiro;
        a++;
    }
    for(a=0;a<id_passageiro;a++){
        for (b=a+1;b<id_passageiro;b++){
            if(vetor[a]<vetor[b]){
                aux=vetor[a];
                vetor[a]=vetor[b];
                vetor[b]=aux;
            }
        }
    }
    printf("Ordenacao concluida com sucesso!\n");
    printf("Os passageios estão em ordem decrescente!\n");
    int p, x=0;
       for (p=0; p<id_passageiro; p++){
        printf("%d a embarcar tem ID %d\n", p+1, vetor[x]);
        printf("\n");
            x++;
       }
}

NoLista bubblesort_menorIDdecres (NoLista *l, int id_passageiro){
    int *vetor, a=0, b=0, aux=0;
    NoLista *z;
    vetor=(int*)malloc(sizeof(int)*id_passageiro);

    for (z=l; z!=NULL; z=z->prox){
        vetor[a]=z->passageiro->idPassageiro;
        a++;
    }
    for(a=0;a<id_passageiro;a++){
        for (b=a+1;b<id_passageiro;b++){
            if(vetor[a]>vetor[b]){
                aux=vetor[a];
                vetor[a]=vetor[b];
                vetor[b]=aux;
            }
        }
    }
    printf("Ordenacao concluida com sucesso!\n");
    printf("Os passageios estão em ordem decrescente!\n");
    int p, x=0;
       for (p=0; p<id_passageiro; p++){
        printf("%d a embarcar tem ID %d\n", p+1, vetor[x]);
        printf("\n");
            x++;
       }
}

void quick_menormalascres(NoLista *l, int id_passageiro, int left, int right){
    int *v, i, j, x, y, a=0;
    NoLista *g;
    int n;
    v=(int*)malloc(sizeof(int)*id_passageiro);
    for(g=l;  g!=NULL; g=g->prox){
        v[a]=g->mala->quant_mala;
        a++;
    }

    i=left;
    j=right;
    n= v[(left+right)/2];
    while(i<=j){
        while(v[i] < n && i <right){
            i++;
        }
        while(v[j] > n && j > left){
            j--;
        }
        if(i <= j){
            y=v[i];
            v[i]=v[j];
            v[j]= y;
            i++;
            j--;
        }
    }
    if (j > i){
        quick_menormalascres(l, id_passageiro, left, j);
    }
    if (i < j){
        quick_menormalascres(x, id_passageiro, i, right);
    }
        int p;
        printf("Ordenado com sucesso!\n");
        for (p=0; p<id_passageiro; p++){
            printf("%d a embarcar tem %d mala(s)\n", p+1, v[p]);
            printf("\n");
       }
}

void quick_maiormalascres(NoLista *l, int id_passageiro, int left, int right){
    int *v, i, j, x, y, a=0;
    NoLista *g;
    int n;
    v=(int*)malloc(sizeof(int)*id_passageiro);
    for(g=l;  g!=NULL; g=g->prox){
        v[a]=g->mala->quant_mala;
        a++;
    }

    i=left;
    j=right;
    n= v[(left+right)/2];
    while(i<=j){
        while(v[i] < n && i <right){
            i++;
        }
        while(v[j] > n && j > left){
            j--;
        }
        if(i <= j){
            y=v[i];
            v[i]=v[j];
            v[j]= y;
            i++;
            j--;
        }
    }
    if (j > i){
        quick_menormalascres(l, id_passageiro, left, j);
    }
    if (i < j){
        quick_menormalascres(x, id_passageiro, i, right);
    }

    printf("Ordenado com sucesso!\n");
    int p, r=1;
     for (p=id_passageiro; p>0; p--){
        printf("%d a embarcar tem id %d\n",r, v[p-1]);
        printf("\n");
        r++;
    }
}

void quick_menorIDdecres(NoLista *l, int id_passageiro, int left, int right){
    int *v, i, j, x, y, a=0;
    NoLista *g;
    int n;
    v=(int*)malloc(sizeof(int)*id_passageiro);
    for(g=l;  g!=NULL; g=g->prox){
        v[a]=g->passageiro->idPassageiro;
        a++;
    }

    i=left;
    j=right;
    n= v[(left+right)/2];
    while(i<=j){
        while(v[i] < n && i <right){
            i++;
        }
        while(v[j] > n && j > left){
            j--;
        }
        if(i <= j){
            y=v[i];
            v[i]=v[j];
            v[j]= y;
            i++;
            j--;
        }
    }
    if (j > i){
        quick_menormalascres(l, id_passageiro, left, j);
    }
    if (i < j){
        quick_menormalascres(x, id_passageiro, i, right);
    }
        int p;
        printf("Ordenado com sucesso!\n");
        for (p=0; p<id_passageiro; p++){
            printf("%d a embarcar tem ID = %d\n", p+1, v[p]);
            printf("\n");
       }
}

void quick_maiorIDdecres(NoLista *l, int id_passageiro, int left, int right){
    int *v, i, j, x, y, a=0;
    NoLista *g;
    int n;
    v=(int*)malloc(sizeof(int)*id_passageiro);
    for(g=l;  g!=NULL; g=g->prox){
        v[a]=g->passageiro->idPassageiro;
        a++;
    }

    i=left;
    j=right;
    n= v[(left+right)/2];
    while(i<=j){
        while(v[i] < n && i <right){
            i++;
        }
        while(v[j] > n && j > left){
            j--;
        }
        if(i <= j){
            y=v[i];
            v[i]=v[j];
            v[j]= y;
            i++;
            j--;
        }
    }
    if (j > i){
        quick_menormalascres(l, id_passageiro, left, j);
    }
    if (i < j){
        quick_menormalascres(x, id_passageiro, i, right);
    }

    printf("Ordenado com sucesso!\n");
    int p, r=1;
     for (p=id_passageiro; p>0; p--){
        printf("%d a embarcar tem ID = %d\n",r, v[p-1]);
        printf("\n");
        r++;
    }
}
