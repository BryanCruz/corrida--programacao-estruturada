#include<stdio.h>
#include<stdlib.h>
/* 
 * Comprimento do percurso: 100km
 * Correr: 10km/h
 * andar: 5km/h
*/

typedef struct s_funcao * funcao;

struct s_funcao{
    //ef = ei + v*t;
    double ef;
    double ei;
    int v;
    double t;
    
    funcao prox;
};

funcao nova_funcao(double ef, double ei, int v, double t){
    funcao func = (funcao) malloc(sizeof(struct s_funcao));
    if(func == NULL){
      fprintf(stderr, "Erro na alocação de memória\n");
      exit(1);
    }

    func->ef = ef;
    func->ei = ei;
    func->v = v;
    func->t = t;
    func->prox = NULL;

    return func;
}

typedef struct s_instrucao * instrucao;

struct s_instrucao{
    char v;
    double frac;
    char tipo;
    instrucao prox;
};

instrucao nova_instrucao(char v, char frac1, char frac2, char tipo){
    instrucao instruc = (instrucao) malloc(sizeof(struct s_instrucao));
    if(instruc == NULL){
      fprintf(stderr, "Erro na alocação de memória\n");
      exit(1);
    }

    instruc->v = v;
    instruc->frac = (1.0*(frac1-'0'))/(frac2-'0');
    instruc->tipo = tipo;
    instruc->prox = NULL;
    return instruc;
}
int main(){
    instrucao instrucoes = NULL;
    char v, tipo, frac1, frac2;
    while(scanf("%c", &v) > 0 && v != '\n'){
        scanf("%c", &frac1);
        scanf("%c", &frac2);
        scanf("%c", &tipo);
    
        instrucao instruc = nova_instrucao(v, frac1, frac2, tipo);
        instruc->prox = instrucoes;
        instrucoes = instruc;
    }
    
    while(instrucoes != NULL){
        printf("v: %c\nfrac: %.2lf\ntipo: %c\n\n", instrucoes->v, instrucoes->frac, instrucoes->tipo);
        instrucoes = instrucoes->prox;
    }


	return 0;
}
