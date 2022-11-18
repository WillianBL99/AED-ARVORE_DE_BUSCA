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

typedef struct Pessoa {
  string cpf;
  string nome;
  int idade;
  int salario;
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
void menu(int, Arvore*, bool*);
void inserirFuncionario(Arvore*, Pessoa*);
void inserirFuncionarios(Arvore*, int);
string gerarCPF();
string gerarNome();
int opcoes();
int gerarIdade();
int gerarSalario();
No *criaNovoNo(Pessoa*);
No *removeFuncionario(Arvore*, string);
Arvore *inicializaArvore();
No *buscaFuncionario(Arvore*, string);

int main() {
  bool continuar = true;
  setlocale(LC_ALL, "Portuguese");
  Arvore *funcionarios = inicializaArvore();

  while(continuar) {
    menu(opcoes(), funcionarios, &continuar);
  }

  cout << "Programa finalizado!" << endl;
  return 0;
}

int opcoes() {
  string opcoesMenu[] = {
    "Sair",
    "Cadastrar Funcionarios",
    "Cadastrar um Funcionario",
    "Exibir Funcionarios",
    "Remover Funcionario",
    "Buscar Funcionario"
  };
  int opcao = 0;

  cout << "--- Menu ---" << endl;
  for(int i = 1; i < 6; i++) {
    cout << i << " - " << opcoesMenu[i] << endl;
  }
  cout << "0 - " << opcoesMenu[0] << endl;

  cout << "Opção: ";
  cin >> opcao;
  return opcao;
}

void menu(int opcao, Arvore *funcionarios, bool *continuar) {
  int qtdFuncionarios = 0;
  string cpf;
  No *funcionario;
  switch(opcao) {
    case 1:
      cout << "Quantos funcionarios deseja inserir? ";
      cin >> qtdFuncionarios;
      inserirFuncionarios(funcionarios, qtdFuncionarios);
      break;
    case 2:
      cout << "em construção" << endl;
      break;
    case 3:
      exibeFuncionarios(funcionarios->raiz);
      break;
    case 4:
      cout << "Insira o CPF do funcionario: ";
      cin >> cpf;
      funcionario = buscaFuncionario(funcionarios, cpf);
      exibeFuncionarios(funcionario);
      break;

    case 5:
      cout << "Insira o CPF do funcionario: ";
      cin >> cpf;
      funcionario = buscaFuncionario(funcionarios, cpf);
      exibeFuncionarios(funcionario);
      break;
    case 0:
      *continuar = false;
      break;
    default:
      cout << "Opção inválida!" << endl;
      break;
  }
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

No *buscaFuncionario(Arvore *arvore, string cpf) {
  if(ehNull(arvore->raiz)) {
    cout << PESSOA_NAO_ENCONTRADA << endl;
    return NULL;
  }

  No *no = busca(arvore->raiz, cpf);

  if(ehNull(no)) {
    cout << PESSOA_NAO_ENCONTRADA << endl;
    return NULL;
  }

  return no;
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

string gerarCPF() {
  string cpf = "";
  const int TAMANHO_CPF = 11;
  for(int i = 0; i < TAMANHO_CPF; i++) {
    if(i == 3 || i == 6) {
      cpf += ".";
    } else if(i == 9) {
      cpf += "-";
    }
    
    cpf += to_string(rand() % 10);
  }
  return cpf;
}

string gerarNome() {
  string nome = "";
  const int INICIO_MIN = 97;
  const int INICIO_MAI = 65;
  const int TAMANHO_ALFABETO = 26;
  const int TAMANHO_NOME = rand() % 10 + 3;

  for(int i = 0; i < TAMANHO_NOME; i++) {
    if(i == 0) {
      nome += (char) (rand() % TAMANHO_ALFABETO + INICIO_MAI);
    } else {
      nome += (char) (rand() % TAMANHO_ALFABETO + INICIO_MIN);
    }
  }

  return nome;
}

int gerarIdade() {
  const int IDADE_MIN = 18;
  const int IDADE_MAX = 65;
  return rand() % (IDADE_MAX - IDADE_MIN + 1) + IDADE_MIN;
}

int gerarSalario() {
  const int SALARIO_MIN = 1000;
  const int SALARIO_MAX = 10000;
  return rand() % (SALARIO_MAX - SALARIO_MIN + 1) + SALARIO_MIN;
}

void inserirFuncionarios(Arvore *arvore, int tamanho) {
  for(int i = 0; i < tamanho; i++) {
    Pessoa *pessoa = new Pessoa;
    pessoa->nome = gerarNome();
    pessoa->idade = gerarIdade();
    pessoa->salario = gerarSalario();
    pessoa->cpf = gerarCPF();
    inserirFuncionario(arvore, pessoa);
  }

  cout << "Funcionários inseridos com sucesso!" << endl;
}