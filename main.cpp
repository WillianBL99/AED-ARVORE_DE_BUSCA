#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
int ARVORE_CHEIA[] = { 12, 6, 18, 3, 9, 14, 22, 2, 4, 8, 10, 13, 15, 21, 23 };
int ARVORE_ZIGZAG[] = { 5, 6, 7, 8, 9, 19, 18, 10, 11, 12, 13, 14, 15, 16, 17 };
int ARVORE_ZIGZAG1[] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

typedef struct No {
  int info;
  struct No *dir;
  struct No *esq;
} No;

typedef struct Arvore {
  No *raiz;
} Arvore;

bool ehNull(No*);

No *criaNovoNo(int);
No* buscar(No*, int);

void inserir(Arvore*, int);
void exibirArvore(No*, int = 0);
void liberar(No*);
void liberarArvore(Arvore*);
void inserirValores(Arvore*, string);

Arvore *inicializaArvore(Arvore*);

int main() {
  Arvore *arvore;
  arvore = inicializaArvore(arvore);
  inserirValores(arvore, "cheia");
  liberarArvore(arvore);
  inserirValores(arvore, "zigzag");
  liberarArvore(arvore);
  inserirValores(arvore, "zigzag1");
  liberarArvore(arvore);

  return 0;
}

void inserirValores(Arvore *arvore, string tipo) {
  int *vetor;
  int tamanho;

  if(tipo == "cheia") {
    vetor = ARVORE_CHEIA;
    tamanho = sizeof(ARVORE_CHEIA) / sizeof(int);
  } else if(tipo == "zigzag") {
    vetor = ARVORE_ZIGZAG;
    tamanho = sizeof(ARVORE_ZIGZAG) / sizeof(int);
  } else if(tipo == "zigzag1") {
    vetor = ARVORE_ZIGZAG1;
    tamanho = sizeof(ARVORE_ZIGZAG1) / sizeof(int);
  } else {
    cout << "Tipo de árvore inválido!" << endl;
    return;
  }

  for (int i = 0; i < tamanho; i++) {
    inserir(arvore, vetor[i]);
  }

  cout << "Arvore tipo: " << tipo << endl;
  cout << "--------------------------------------------" << endl;
  exibirArvore(arvore->raiz);
}

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

// Realiza a leitura dos nos em ordem decrescente
void exibirArvore(No *raiz, int nivel) {
  if(ehNull(raiz)) {
    return;
  }

  exibirArvore(raiz->dir, nivel + 1);

  for(int i = 0; i < nivel; i++) {
    cout << "    |";
  }  

  cout << "-";  
  if(raiz->info < 10) cout << "0";
  cout << raiz->info << "-|" <<endl;

  exibirArvore(raiz->esq, nivel + 1);
}

void liberar(No *no) {
  if(ehNull(no)) {
    return;
  }

  liberar(no->esq);
  liberar(no->dir);
  free(no);
}

void liberarArvore(Arvore *arvore) {
  if(ehNull(arvore->raiz)) {
    return;
  }

  liberar(arvore->raiz);
  arvore->raiz = NULL;  
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
