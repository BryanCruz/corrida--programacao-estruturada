#include<stdio.h>
#include<stdlib.h>
/*
 * Comprimento do percurso: 100km
 * Correr: 10km/h
 * andar: 5km/h
*/

typedef struct s_funcao * funcao;

struct s_funcao{
  double a;
  double b;
};

funcao nova_funcao(double a, double b){
    funcao f = (funcao) malloc(sizeof(struct s_funcao));
    if(f == NULL){
      fprintf(stderr, "Erro na alocação de memória\n");
      exit(1);
    }

    f->a = a;
    f->b = b;
    return f;
}

typedef struct s_instrucao * instrucao;

struct s_instrucao{
    double v;
    double fracao;
    char tipo;
    instrucao prox;
};

instrucao nova_instrucao(double v, double fracao, char tipo){
    instrucao i = (instrucao) malloc(sizeof(struct s_instrucao));
    if(i == NULL){
      fprintf(stderr, "Erro na alocação de memória\n");
      exit(1);
    }

    i->v;
    i->fracao = fracao;
    i->tipo = tipo;
    i->prox = NULL;
    return i;
}
int main(){
    instrucao instrucoes = NULL;
    char qual_v, tipo, frac1, frac2;
    while(scanf("%c", &qual_v) > 0 && qual_v != '\n'){
        scanf("%c", &frac1);
        scanf("%c", &frac2);
        scanf("%c", &tipo);

        double v = qual_v == 'A'? 5 : 10;
        double fracao = (1.0*(frac1 - '0'))/(frac2 - '0');
        instrucao i = nova_instrucao(v, fracao, tipo);
        i->prox = instrucoes;
        instrucoes = i;
    }

    while(instrucoes != NULL){
        printf("v: %.2lf\nfrac: %.2lf\ntipo: %c\n\n", instrucoes->v, instrucoes->fracao, instrucoes->tipo);
        instrucoes = instrucoes->prox;
    }


	return 0;
}
