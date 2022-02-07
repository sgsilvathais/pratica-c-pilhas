#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct numero
{
    int num;
    struct numero *ant;
} TipoNumero;

typedef struct pilha
{
    TipoNumero *topo;
    int tamanhoPilha;
} TipoPilha;

void iniciaPilha(TipoPilha *pilhaAux)
{
    pilhaAux->topo = NULL;
    pilhaAux->tamanhoPilha = 0;
}

void binParaDec(TipoPilha *pilhaAux, int x)
{
    int resto;
    TipoNumero *aux;

    if(x == 0){
        aux->num = resto;
        aux->ant = NULL;
        pilhaAux->topo = aux;
        pilhaAux->tamanhoPilha++;
    }
    else
    {
        while(x != 0)
        {       
            aux = malloc(sizeof(TipoNumero)); 
            resto = x % 2;
            x /= 2;
            aux->num = resto;
            aux->ant = pilhaAux->topo;
            pilhaAux->topo = aux;
            pilhaAux->tamanhoPilha++;
        }
    }
}

int func_exp(int num1, int num2)
{
    int i, result = 1;

    for(i = 0; i < num2; i++)
        result *= num1;

    return result;
}

int decTransformado(TipoPilha *pilhaAux)
{
    int y = pilhaAux->tamanhoPilha - 1, decimal = 0, x = 2;
    TipoNumero *aux = pilhaAux->topo;

    while(aux != NULL)
    {
        if(aux->num == 0)
            decimal += func_exp(x, y);
        aux = aux->ant;
        y--;
    }

    return decimal;
}

void imprimeBin(TipoPilha *pilhaAux)
{
    TipoNumero *aux = pilhaAux->topo;

    while(aux != NULL)
    {
        printf("%d", aux->num);
        aux = aux->ant;
    }

    printf(" ");
}

void imprimeBinTransf(TipoPilha *pilhaAux)
{
    TipoNumero *aux = pilhaAux->topo;

    while(aux != NULL)
    {
        if(aux->num == 0)
            printf("1");
        else
            printf("0");
        aux = aux->ant;
    }

    printf(" ");
}

void liberaMemoria(TipoPilha *pilhaAux)
{
    TipoNumero *aux;

    while(pilhaAux->tamanhoPilha != 0)
    {     
        aux = pilhaAux->topo;     
        pilhaAux->topo = aux->ant;
        free(aux);
        pilhaAux->tamanhoPilha--;
    }
}
int main (void)
{
    int qtd, num, i;
    TipoPilha pilha;

    iniciaPilha(&pilha);

    scanf("%d", &qtd);

    if(qtd >= 1 && qtd <= 100)
    {
        for (i = 0; i < qtd; i++)
        {
            scanf("%d", &num);
            binParaDec(&pilha, num);
            decTransformado(&pilha);
            printf("%d ", num);
            imprimeBin(&pilha);
            imprimeBinTransf(&pilha);
            printf("%d\n", decTransformado(&pilha));
            liberaMemoria(&pilha);
        }
    } else exit(1);

    return 0;
}
