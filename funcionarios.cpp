#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const string PESSOA_JA_CADASTRADA = "Pessoa já cadastrada!";
const string PESSOA_NAO_CADASTRADA = "Pessoa não cadastrada!";
const string PESSOA_NAO_ENCONTRADA = "Pessoa não encontrada!";
const string PESSOA_REMOVIDA_COM_SUCESSO = "Pessoa removida com sucesso!";
const string PESSOA_CADASTRADA_COM_SUCESSO = "Pessoa cadastrada com sucesso!";
const string SEM_CADASTROS = "Não há funcionários cadastrados!";

string CPFs[] = { "222.222.222-22", "111.111.111-11", "333.333.333-33", "444.444.444-44" };
string nomes[] = { "Paulo", "Fernanda", "João", "Maria" };
int idades[] = { 20, 30, 40, 50 };
float salarios[] = { 1000.00, 2000.00, 3000.00, 4000.00 };


typedef struct Pessoa {
  string cpf;
  string nome;
  int idade;
  float salario;
} Pessoa;

typedef struct No {
  Pessoa *info;
  struct No *dir;
  struct No *esq;
} No;

typedef struct Arvore {
  No *raiz;
  int tamanho;
} Arvore;

bool ehNull(No*);
void exibeFuncionarios(No*);
void inserirFuncionario(Arvore*, Pessoa*);
No *criaNovoNo(Pessoa*);
No *removeFuncionario(Arvore*, string);
Arvore *inicializaArvore();
Pessoa *buscaFuncionario(No*, string);

int main() {
  setlocale(LC_ALL, "Portuguese");
  Arvore *funcionarios = inicializaArvore();

  int tamanho = sizeof(CPFs) / sizeof(CPFs[0]);
  for(int i = 0; i < tamanho; i++) {
    Pessoa *pessoa = new Pessoa;
    pessoa->cpf = CPFs[i];
    pessoa->nome = nomes[i];
    pessoa->idade = idades[i];
    pessoa->salario = salarios[i];
    inserirFuncionario(funcionarios, pessoa);
  }

  exibeFuncionarios(funcionarios->raiz);

  return 0;
}

bool ehNull(No *no) {
  return no == NULL;
}

Arvore *inicializaArvore() {
  Arvore *arvore = (Arvore*) malloc(sizeof(Arvore));
  arvore->raiz = NULL;
  arvore->tamanho = 0;
  return arvore;
}

No *criaNovoNo(Pessoa *pessoa) {
  No *novoNo = (No*) malloc(sizeof(No));
  novoNo->info = pessoa;
  novoNo->dir = NULL;
  novoNo->esq = NULL;
  return novoNo;
}

void inserirFuncionario(Arvore *arvore, Pessoa *pessoa) {
  No *novoNo = criaNovoNo(pessoa);
  No *atual = arvore->raiz;
  No *anterior = NULL;

  while(!ehNull(atual)) {
    anterior = atual;

    if(pessoa->cpf.compare(atual->info->cpf) == 0) {
      cout << PESSOA_JA_CADASTRADA << endl;
      return;
    } else if(pessoa->cpf.compare(atual->info->cpf) < 0) {
      atual = atual->esq;
    } else {
      atual = atual->dir;
    }
  }

  if(ehNull(anterior)) {
    arvore->raiz = novoNo;
  } else if(pessoa->cpf.compare(anterior->info->cpf) < 0) {
    anterior->esq = novoNo;
  } else {
    anterior->dir = novoNo;
  }

  arvore->tamanho++;
}

void exibeFuncionarios(No *no) {
  if(ehNull(no)) {
    return;
  }

  exibeFuncionarios(no->esq);
  cout << "CPF: " << no->info->cpf << endl;
  cout << "Nome: " << no->info->nome << endl;
  cout << "Idade: " << no->info->idade << endl;
  cout << "Salário: " << no->info->salario << endl;
  cout << "---------------------------------" << endl;
  exibeFuncionarios(no->dir);
}

No *busca(No *no, string cpf) {
  if(ehNull(no)) {
    return NULL;
  }

  if(cpf.compare(no->info->cpf) == 0) {
    return no;
  } else if(cpf.compare(no->info->cpf) < 0) {
    return busca(no->esq, cpf);
  } else {
    return busca(no->dir, cpf);
  }
}

Pessoa *buscaFuncionario(Arvore *arvore, string cpf) {
  if(ehNull(arvore->raiz)) {
    cout << PESSOA_NAO_ENCONTRADA << endl;
    return NULL;
  }

  No *no = busca(arvore->raiz, cpf);

  if(ehNull(no)) {
    cout << PESSOA_NAO_ENCONTRADA << endl;
    return NULL;
  }

  return no->info;
}

No *removeFuncionario(Arvore *arvore, string cpf) {
  if(ehNull(arvore->raiz)) {
    cout << SEM_CADASTROS << endl;
    return NULL;
  }

  No *noPai = NULL;
  No *noAtual = arvore->raiz;

  while(!ehNull(noAtual) && noAtual->info->cpf.compare(cpf) != 0) {
    noPai = noAtual;
    if(cpf.compare(noAtual->info->cpf) < 0) {
      noAtual = noAtual->esq;
    } else {
      noAtual = noAtual->dir;
    }
  }

  if(ehNull(noAtual)) {
    cout << PESSOA_NAO_ENCONTRADA << endl;
    return NULL;
  }

  No* noAux = NULL;

  if(ehNull(noAtual->esq)) {
    noAux = noAtual->dir;

  } else if(ehNull(noAtual->dir)) {
    noAux = noAtual->esq;

  } else {
    noAux = noAtual->esq;
    No *noAuxPai = noAtual;
    
    while(!ehNull(noAux->dir)) {
      noAuxPai = noAux;
      noAux = noAux->dir;
    }

    if(noAuxPai != noAtual) {
      noAuxPai->dir = noAux->esq;
      noAux->esq = noAtual->esq;
    }

    noAux->dir = noAtual->dir;
  }

  No *noRemovido = noAtual;
  arvore->tamanho--;

  return noRemovido;
}