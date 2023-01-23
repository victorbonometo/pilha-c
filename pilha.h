#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXIMO 100

typedef struct p{
  int elementos[MAXIMO];
  int topo;

}pilha;   //define o TAD pilha

void CriaPilha(pilha *p){
  p->topo = -1;
}

bool PilhaVazia(pilha *p){
  if(p->topo==-1){
    return true;
  }
  else 
    return false;
}

bool PilhaCheia(pilha *p){
  if(p->topo==(MAXIMO-1)){
    return true;
  }
  else
    return false;
}

void Empilha(pilha *p, int *x, bool *DeuCerto){
  if (PilhaCheia(p)==1){
    printf("Pilha cheia!");
  }
  else{
    p->topo++;
    p->elementos[p->topo]=x;
    *DeuCerto=true;
  }
}

void Desempilha(pilha*p, int *x, bool *DeuCerto){
  if(PilhaVazia(p)==1){
    printf("Pilha vazia!");
  }
  else{
    *x=p->elementos[p->topo];
    p->topo--;
    *DeuCerto=true;
  }
}
