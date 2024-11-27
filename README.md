# ALOCAÇÃO DE MEMÓRIA DINÂMICA

Implementação de lista com alocação dinâmica de memória.
## Alterações realizadas

Foi necessário a alteração da struct, removendo a declaração estática.

```c++
typedef struct {
  REGISTRO *A;
  int nroElem;
  int capacidade;
} LISTA;
```

Como não esta sendo mais estático, realizei algumas alterações nas funções fornecidas:
```c++
int tamanhoEmBytes(LISTA* l) {
  return l->capacidade * sizeof(REGISTRO);
} 
```
Para facilitar o teste do código na parte de redução de espaço, foi implementado a função de exclusão da último elemento:
```c++
bool excluirUltimoElem(LISTA* l) { 
  if(l->nroElem<= (l->capacidade/4)) resize(l, l->capacidade/4);
  REGISTRO reg;
  reg.chave = 0;
  l->A[l->nroElem] = reg;
  l->nroElem--;
  return true;
} 
```
## Função principal

```c++
void resize(LISTA* l, int novo_tamanho){

  if(novo_tamanho > l->capacidade) printf("Expandindo a capacidade de %i para %i...\n\n",l->capacidade, novo_tamanho);
  else printf("Reduzindo a capacidade de %i para %i...\n\n",l->capacidade, novo_tamanho);
  //VERIFICA SE ESTAMOS EXPANDIDO OU RETRAINDO ESPAÇO

  REGISTRO* novo_array; //PONTEIRO PARA NOVO ESPAÇO

  novo_array = malloc(novo_tamanho * sizeof(int)); //ALOCAÇÃO PARA A LISTA COM O NOVO ESPAÇO

  if (novo_array == NULL) {
    printf("Erro: Memória insuficiente para redimensionar.\n");
    return;
    
  }
  
  for(int i = 0; (i < novo_tamanho) && (i < l->nroElem); i++) novo_array[i] = l->A[i]; //CÓPIA ELEMENTO A ELEMENTO

  free(l->A); //LIBERAÇÃO DO ARRAY COM O ESPAÇO ANTIGO

  l->A = novo_array; //APONTAMENTO PARA O NOVO ARRAY

  if (novo_tamanho > l->capacidade) {
        for (int i = l->nroElem; i < novo_tamanho; i++) {
            REGISTRO reg;
            reg.chave = 0;
            l->A[i] = reg;
        }
  }

  //PREENCHIMENTO DOS ESPAÇOS ECXEDENTES POR 0
  
  l->capacidade = novo_tamanho;
  //REGISTRO DA NOVA CAPACIDADE

}
```

Essa função recebe o ponteiro da lista, faz outra lista com o tamanho passado no parametro, copia os itens para essa nova lista e altera o ponteiro da lista passada para a lista criada.


## Licença

[Marcos](https://github.com/MarcosAerospaceEng?tab=repositories)