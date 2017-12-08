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
    f->a = a;
    f->b = b;
    return f;
}

funcao soma(funcao f, funcao g){
  funcao h = nova_funcao(f->a + g->a, f->b + g->b);
  return h;
}


funcao multiplicacao(funcao f, double c){
  funcao h = nova_funcao(c*f->a, c*f->b);
  return h;
}

funcao inversa(funcao f){
  funcao h = nova_funcao(1/f->a, -f->b/f->a);
  return h;
}

funcao composicao(funcao f, funcao g){
  funcao h = nova_funcao(f->a*g->a, f->a*g->b + f->b);
  return h;
}

double resultado_funcao(funcao f, double x){
  return f->a*x + f->b;
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

    i->v = v;
    i->fracao = fracao;
    i->tipo = tipo;
    i->prox = NULL;
    return i;
}

int contar_instrucoes(instrucao instrucoes){
  int n = 0;
  instrucao i = instrucoes;
  while(i != NULL){
    n++;
    i = i->prox;
  }
  return n;
}

double calcular_tempo(instrucao instrucoes){
  int n = contar_instrucoes(instrucoes);

  funcao funcoes_espacos[n];
  funcao funcoes_tempos[n];

  double tempos[n];
  double espacos[n];

  instrucao i = instrucoes;
  int j = n-1;
  while(j >= 0){
    espacos[j] = -1;
    tempos[j] = -1;

    funcoes_espacos[j] = nova_funcao(instrucoes->v, -1);
    funcoes_tempos[j] = nova_funcao(1/(instrucoes->v), -1);
    if(j == 0){
      funcoes_espacos[j]->b = 0;
      funcoes_tempos[j]->b = 0;
    }else if(j == n-1){
      espacos[j] = 100;
    }

    i = i->prox;
    j--;
  }



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
    printf("%.2lf\n", t);
    while(instrucoes != NULL){
        printf("v: %.2lf\nfrac: %.2lf\ntipo: %c\n\n",
              instrucoes->v, instrucoes->fracao, instrucoes->tipo);
        instrucoes = instrucoes->prox;
    }
  }

	return 0;
}
