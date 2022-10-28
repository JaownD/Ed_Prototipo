#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "PilhaEstatica.h"
#include "FilaEstatica.h"
#define MAX 31

int main()
{
    int quant_time, quant_pote, i, j = 0, k = 0, aux_pote, tam_def = 0, aux_tam, aux, placar, aux_placar;
    char pais[MAX], aux_pais[MAX], pais_passou[MAX];
    char *retirado, *aux_retirado;
    Fila *f = cria_fila();
    Pilha *p_ranking = cria_pilha();

    scanf("%d %d", &quant_time, &quant_pote);

    Pilha **potes = (Pilha**)malloc(quant_pote*sizeof(Pilha*));

    for(i = 0; i < quant_pote; i++)
        potes[i] = cria_pilha();

    for(i = 0; i < quant_time; i++){
        if(j == quant_pote)
            j = 0;
        scanf("%s", pais);
        pushP(potes[j], pais);
        aux_tam = strlen(pais);
        if(aux_tam > tam_def)
            tam_def = aux_tam;
        j++;
    }

for(i = 0; i < quant_pote; i++)
    imprimeP(potes[i]);

///Passando para a fila
    for(i = 0; i < quant_time/2; i++){
        printf("Aqui1");
        j = k + 1;
        if(j == quant_pote)
            j = 0;
        retirado = popP(potes[k]);
        aux_retirado = popP(potes[j]);
        k = j + 1;
        if(k == quant_pote)
            k = 0;
        pushF(f, retirado, aux_retirado);
        printf("\nRetirado: %s\nAux_retirado: %s\n", retirado, aux_retirado);
        //free(aux_retirado);
        //free(retirado);
    }
//imprimeF(f);
printf("Aqui100");

///Disputas
    srand(time(0));
    for(i = 0; i < quant_time/2; i++){
        if(i == ((quant_time/2) - 1))
            printf("\nGrande final: \n");
        else
            printf("\nDia %d: \n", i + 1);
        for(j = 0; j < 2; j++){
            popF(f, pais, aux_pais);     ///OU popF(f, retirado, aux_retirado)?

            placar = rand() %8;
            aux_placar = rand() %8;
            while(placar == aux_placar){
                placar = rand() %8;
                aux_placar = rand() %8;
            }
            aux_tam = strlen(pais);
            aux = tam_def;
            while((aux + 4) != aux_tam){
                printf(" ");
                aux--;
            }
            printf("%s %d x %d %s\n", pais, placar, aux_placar, aux_pais);
            if(i == ((quant_time/2) - 1)){
                if(placar > aux_placar){
                    pushP(p_ranking, aux_placar);
                    pushP(p_ranking, pais);
                }
                else{
                    pushP(p_ranking, pais);
                    pushP(p_ranking, aux_pais);
                }
                printf("Aqui");
                break;
            }
            else if(j == 0){
                if(placar > aux_placar){
                    pushP(p_ranking, aux_pais);
                    strcpy(pais_passou, pais);
                }
                else{
                    pushP(p_ranking, pais);
                    strcpy(pais_passou, aux_pais);
                }
            }
            else{
                if(placar > aux_placar){
                    pushP(p_ranking, aux_pais);
                    pushF(f, pais_passou, pais);
                }
                else{
                    pushP(p_ranking, pais);
                    pushF(f, pais_passou, aux_pais);
                }
            }
        }
    }
imprimeP(p_ranking);
    return 0;
}
