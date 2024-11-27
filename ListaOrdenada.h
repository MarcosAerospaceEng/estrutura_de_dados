// listaSequencialOrdenada.h
#ifndef LISTA_SEQUENCIAL_ORDENADA_H
#define LISTA_SEQUENCIAL_ORDENADA_H

#include <stdio.h>
#define ERRO -1
#define bool int
#define true 1
#define false 0

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct {
  REGISTRO *A;
  int nroElem;
  int capacidade;
} LISTA;

// Declaração das funções
void inicializarLista(LISTA* l);
void exibirLista(LISTA* l);
int tamanho(LISTA* l);
int capacidade(LISTA* l);
int tamanhoEmBytes(LISTA* l);
void reinicializarLista(LISTA* l);
bool inserirElemListaOrd(LISTA* l, REGISTRO reg);
bool excluirUltimoElem(LISTA* l);
void resize(LISTA* l, int novo_tamanho);

#endif // LISTA_SEQUENCIAL_ORDENADA_H
