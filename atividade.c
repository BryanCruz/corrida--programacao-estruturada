#include<stdio.h>
#include<stdlib.h>
/*
 * Comprimento do percurso: 100km
 * Correr: 10km/h
 * andar: 5km/h
*/

typedef struct s_funcao funcao;

struct s_funcao{
  double a;
  double b;
};

funcao nova_funcao(double a, double b){
    funcao f;
    f.a = a;
    f.b = b;
    return f;
}

funcao soma(funcao f, funcao g){
  funcao h = {f.a + g.a, f.b + g.b};
  return h;
}


funcao multiplicacao(funcao f, double c){
  funcao h = {c*f.a, c*f.b};
  return h;
}

funcao inversa(funcao f){
  funcao h = {1/f.a, -f.b/f.a};
  return h;
}

funcao composicao(funcao f, funcao g){
  funcao h = {f.a*g.a, f.a*g.b + f.b};
  return h;
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
      exit(1);
    }

    i->v = v;
    i->fracao = fracao;
    i->tipo = tipo;
    i->prox = NULL;
    return i;
}

double calcular_tempo(instrucao instrucoes){
  return 0;
}

int main(){
  char aux;
  double tMax = -1;
  while(scanf("%c", &aux) > 0){
    instrucao instrucoes = NULL;
    char qual_v, tipo, aux;
    int frac1, frac2;
    int flag = 1;
    do{
      if (flag){
        flag = 0;
        qual_v = aux;
        scanf(" %d %d %c", &frac1, &frac2, &tipo);
      }else{
        scanf("%c %d %d %c", &qual_v, &frac1, &frac2, &tipo);
      }
      double v = qual_v == 'A'? 5 : 10;
      double fracao = (1.0*frac1)/frac2;
      instrucao i = nova_instrucao(v, fracao, tipo);
      i->prox = instrucoes;
      instrucoes = i;

    }while(scanf("%c", &aux) && aux != '\n');


    double t = calcular_tempo(instrucoes);
    printf("%.2lf\n", calcular_tempo(instrucoes));
    /*while(instrucoes != NULL){
        printf("v: %.2lf\nfrac: %.2lf\ntipo: %c\n\n",
              instrucoes->v, instrucoes->fracao, instrucoes->tipo);
        instrucoes = instrucoes->prox;
    }*/
  }

	return 0;
}
