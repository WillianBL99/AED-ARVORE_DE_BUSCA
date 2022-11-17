#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct No {
  int info;
  struct No *dir;
  struct No *esq;
} No;

typedef struct Arvore {
  No *raiz;
} Arvore;

Arvore *inicializaArvore(Arvore *arvore) {
  arvore = (Arvore *) malloc(sizeof(Arvore));
  arvore->raiz = NULL;
  return arvore;
}

No *criaNovoNo(int info) {
    No *novoNo = (No *) malloc(sizeof(No));
    novoNo->info = info;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    return novoNo;
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
      noAtual = buscar(noAtual->esq, valor);
    }

  } else {
    if(ehNull(noAtual->dir)) {
      return NULL;
      
    } else {
      noAtual = buscar(noAtual->dir, valor);
    }
  }

  return noAtual;
}

void inserir(Arvore* arvore, int valor) {
  No *novoNo = criaNovoNo(valor);
  
  No *noAtual = arvore->raiz;

  if(ehNull(noAtual)) {
    arvore->raiz = novoNo;
    return;
  }

  if(!ehNull(buscar(noAtual, valor))) {
    cout << "Valor já existe na árvore" << endl;
    return;
  }

  while(true) {
    if(valor < noAtual->info) {
      if(ehNull(noAtual->esq)) {
        noAtual->esq = novoNo;
        return;
      } else {
        noAtual = noAtual->esq;
      }

    } else {
      if(ehNull(noAtual->dir)) {
        noAtual->dir = novoNo;
        return;
      } else {
        noAtual = noAtual->dir;
      }
    }
  }
}


int main() {
  Arvore *arvore;
  arvore = inicializaArvore(arvore);

  if(buscar(arvore->raiz, 10) == NULL) {
    cout << "Valor não encontrado" << endl;
  } else {
    cout << "Valor encontrado" << endl;
  }

  return 0;
}