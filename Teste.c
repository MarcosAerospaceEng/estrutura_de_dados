//main.c
#include "ListaOrdenada.h"
#include "ListaOrdenada.c"

int main() {
  LISTA lista;
  REGISTRO reg;

  // Inicializar a lista
  inicializarLista(&lista);

  // Exibir lista vazia
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Capacidade de elementos na lista: %i.\n", capacidade(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  // Inserir elementos na lista
  for(int i = 0 ; i < 41; i++){
    reg.chave = i;
    inserirElemListaOrd(&lista, reg);
  }


  printf("\n\n");
  // Exibir lista após inserções
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Capacidade de elementos na lista: %i.\n", capacidade(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  printf("\nAdicionando elementos alem da capacidade inicial:\n");
  for(int i = 42 ; i < 80; i++){
    // printf("%i", i);
    reg.chave = i;
    inserirElemListaOrd(&lista, reg);
  }
  printf("\n");

  // resize(&lista,80);

  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Capacidade de elementos na lista: %i.\n", capacidade(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  printf("\n");
  printf("\nRemovendo elementos para baixo dos 25 porcento da capacidade:\n");
  for(int i = 0 ; i < 60; i++){
    excluirUltimoElem(&lista);
  }

  printf("\n");
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Capacidade de elementos na lista: %i.\n", capacidade(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  return 0;
}
