#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct No {
  int info;
  struct No *dir;
  struct No *esq;
} No;

typedef struct No *Arvore;

Arvore *inicializarArvore(Arvore *arvore) {
    return NULL;
}

bool ehNull(No *no) {
    return no == NULL;
}

No* buscar(No *raiz, int valor) {
  if(ehNull(raiz)) {
    return NULL;
  }

  No *noAtual = raiz;

  if(valor == noAtual->info) {
    return noAtual;

  } else if(valor < noAtual->info) {
    if(ehNull(noAtual->esq)) {
      return NULL;

    } else {
      noAtual = noAtual->esq;
      buscar(noAtual, valor);
    }

  } else {
    if(ehNull(noAtual->dir)) {
      return NULL;
      
    } else {
      noAtual = noAtual->dir;
      buscar(noAtual, valor);
    }
  }

  return NULL;
}


int main() {
  Arvore *arvore;
  arvore = inicializarArvore(arvore);

  if(buscar((No*)arvore, 10) == NULL) {
    cout << "Valor não encontrado" << endl;
  } else {
    cout << "Valor encontrado" << endl;
  }


  return 0;
}