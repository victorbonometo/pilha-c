#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

//prototipos
void CriaPilha(pilha *p); //cria uma pilha

bool PilhaVazia(pilha *p); //indica se a pilha está vazia

bool PilhaCheia(pilha *p); //indica se a pilha está cheia

void Empilha(pilha *p, int *x, bool *DeuCerto); //empilha um inteiro na pilha

void Desempilha(pilha *p, int *x, bool *DeuCerto); //desempilha o elemento do topo da pilha

void Imprime(pilha *p){     //imprime os valores da pilha
  int z;
  pilha Paux;
  bool deucerto;

  CriaPilha(&Paux);
  
  while(PilhaVazia(p)==false){
    Desempilha(p, &z, &deucerto);
    if(deucerto){
      Empilha(&Paux, z, &deucerto);
    }

  }
  
  while(PilhaVazia(&Paux)==false){
    Desempilha(&Paux, &z, &deucerto);
    if(deucerto){
      printf("%d \n",z);
      Empilha(p, z, &deucerto);
    }
  }
}

int TotalPilha(pilha *p,  bool *DeuCerto){  //retorna o numero de elementos da pilha
  int x;
  int total = -1;
  bool deucerto;
  pilha Paux;

  while(PilhaVazia(p)==false){
    Desempilha(p, &x, &deucerto);
    if(deucerto){
      Empilha(&Paux, x, &deucerto);
    }

  }
  
  while(PilhaVazia(&Paux)==false){
    Desempilha(&Paux, &x, &deucerto);
    if(deucerto){
      total++;
      Empilha(p, x, &deucerto);
      
    }
  }

  return total;
}

int main(){
  pilha p;
  CriaPilha(&p);
  bool certo;
  int n;

 
  Empilha(&p, 1, &certo);
  Empilha(&p, 2, &certo);
  Empilha(&p, 3, &certo);
   printf("Imprimindo os elementos da pilha: \n ");
  Imprime(&p);

  printf("Exibindo o total de elementos da pilha: \n");
  n = TotalPilha(&p, &certo);
  printf("%d",n);
  
}
