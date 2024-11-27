// ListaOrdenada.c
#include "ListaOrdenada.h"
#include <stdlib.h>

void inicializarLista(LISTA* l){
  l->nroElem = 0;
  l->A = malloc(50 * sizeof(REGISTRO));
  l->capacidade = 50;
}

void exibirLista(LISTA* l){
  int i;
  printf("Lista: \" ");
  for (i=0; i < l->nroElem; i++)
    printf("%i ", l->A[i].chave);
  printf("\"\n");
} 

int tamanho(LISTA* l) {
  return l->nroElem;
}

int capacidade(LISTA* l) {
  return l->capacidade;
}

int tamanhoEmBytes(LISTA* l) {
  return l->capacidade * sizeof(REGISTRO);
} 

TIPOCHAVE primeiroElem(LISTA* l){
  if(l->nroElem > 0) return l->A[0].chave;
  else return ERRO; // lista vazia
} /* primeiroElem */

TIPOCHAVE ultimoElem(LISTA* l) {
  if(l->nroElem > 0) return l->A[l->nroElem-1].chave;
  else return ERRO; // lista vazia
} 

TIPOCHAVE enesimoElem(LISTA* l, int n) {
  if( (n >= 0) && (n < l->nroElem)) return l->A[n].chave ;
  else return ERRO;
} /* enesimoElem */

void reinicializarLista(LISTA* l) {
  l->nroElem = 0;
} /* reinicializarLista */

bool excluirUltimoElem(LISTA* l) { 
  if(l->nroElem<= (l->capacidade/4)) resize(l, l->capacidade/4);
  REGISTRO reg;
  reg.chave = 0;
  l->A[l->nroElem] = reg;
  l->nroElem--;
  return true;
} 

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  if(l->nroElem >= l->capacidade) resize(l, l->capacidade * 2);  // lista cheia <== Aqui tem que aumentar a memória
//if(l->nroElem >= MAX) resize(l, l->nroElem * 2)
  int pos = l->nroElem;
  while(pos > 0 && l->A[pos-1].chave > reg.chave) {
    l->A[pos] = l->A[pos-1];
    pos--;
  }
  l->A[pos] = reg;
  l->nroElem++;
  return true;
}

void resize(LISTA* l, int novo_tamanho){

  if(novo_tamanho > l->capacidade) printf("Expandindo a capacidade de %i para %i...\n\n",l->capacidade, novo_tamanho);
  else printf("Reduzindo a capacidade de %i para %i...\n\n",l->capacidade, novo_tamanho);

  REGISTRO* novo_array;

  novo_array = malloc(novo_tamanho * sizeof(int));

  if (novo_array == NULL) {
    printf("Erro: Memória insuficiente para redimensionar.\n");
    return;
  }
  
  for(int i = 0; (i < novo_tamanho) && (i < l->nroElem); i++) novo_array[i] = l->A[i];

  free(l->A);

  l->A = novo_array;

  if (novo_tamanho > l->capacidade) {
        for (int i = l->nroElem; i < novo_tamanho; i++) {
            REGISTRO reg;
            reg.chave = 0;
            l->A[i] = reg;
        }
  }
  
  l->capacidade = novo_tamanho;

}
