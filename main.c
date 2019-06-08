#include "Biblioteca.h"

int main(){
    int opcao, op1, op2, op3;
    int id_passageiro=0,id_mala=0;
    int *r;
    NoFila *f;
    f=cria_fila();
    NoPilha *p;
    p=cria_pilha();
    NoLista *l=criar_l(l);

        do{
            menu();
            scanf("%d",&opcao);
            getchar();
            system("clear");
            switch(opcao){
                        case 1:
                            system("cls");
                            f=insert_fila(f,id_passageiro);
                            p=insert_pilha(p,id_mala);
                            l=insert_l(l,f,p,id_mala);
                            id_passageiro++;
                            id_mala++;
                            break;
                        case 2:
                            system("cls");
                            mostrar_lista(l);
                            break;
                        case 3:
                            system("cls");
                            busca_sequencial (l);
                            break;
                        case 4:
                            system("cls");
                            busca_sequencial2 (l);
                            break;
                        case 5:
                            system("cls");
                            r=parabusca(l, id_passageiro, 0, id_mala-1);
                            printf("Resultado = %d\n", busca_binaria1 (l, r, id_passageiro));
                            break;
                        case 6:
                            system("cls");
                            r=parabusca(l, id_passageiro, 0, id_mala-1);
                            printf("Resultado = %d\n",busca_binaria2 (l, r, id_passageiro));
                            break;
                        case 7:
                            system("cls");
                            bubblesort_menorqtdMcres (l, id_passageiro);
                            break;
                        case 8:
                            system("cls");
                            bubblesort_maiorqtdMCres (l, id_passageiro);
                            break;
                        case 9:
                            system("cls");
                            bubblesort_menorqtdMcres (l, id_passageiro);
                            break;
                        case 10:
                            system("cls");
                            bubblesort_maiorqtdMDecres(l, id_passageiro);
                            break;
                        case 11:
                            bubblesort_menorIDcres (l, id_passageiro);
                            break;
                        case 12:
                            system("cls");
                            bubblesort_maiorIDcres (l, id_passageiro);
                            break;
                        case 13:
                            system("cls");
                            bubblesort_menorIDcres (l, id_passageiro);
                            break;
                        case 14:
                            system("cls");
                            bubblesort_maiorIDdecres (l, id_passageiro);
                            break;
                        case 15:
                            system("cls");
                            quick_menormalascres(l, id_passageiro, 0, id_mala-1);
                            break;
                        case 16:
                            system("cls");
                            quick_maiormalascres(l, id_passageiro, 0, id_mala-1);
                            break;
                        case 17:
                            system("cls");
                            quick_maiormalascres(l, id_passageiro, 0, id_mala-1);
                            break;
                        case 18:
                            system("cls");
                            quick_menormalascres(l, id_passageiro, 0, id_mala-1);
                            break;
                        case 19:
                            system("cls");
                            quick_menorIDdecres(l, id_passageiro, 0, id_mala-1);
                            break;
                        case 20:
                            system("cls");
                            quick_maiorIDdecres(l, id_passageiro, 0, id_mala-1);
                            break;
                        case 21:
                            system("cls");
                            quick_menorIDdecres(l, id_passageiro, 0, id_mala-1);
                            break;
                        case 22:
                            system("cls");
                            quick_maiorIDdecres(l, id_passageiro, 0, id_mala-1);
                            break;
                }
            }while(opcao != 23);
    return 0;
}

