<div align="center">
  <img src="https://cdn3.iconfinder.com/data/icons/data-visualization-3/64/binary-tree-diversity-data-512.png" width="200" height="200" />
  <h1>Arvore Binaria de Busca</h1>
</div>

# Sobre

Este projeto é uma implementação de uma árvore binária de busca em C++. A árvore binária de busca é uma árvore binária em que cada nó possui um valor e dois filhos, um filho à esquerda e um filho à direita. O filho à esquerda possui um valor menor que o nó pai e o filho à direita possui um valor maior que o nó pai. A árvore binária de busca é uma árvore binária que possui a propriedade de que todos os nós à esquerda de um nó são menores que ele e todos os nós à direita são maiores que ele.

# Como executar

## Pré-requisitos

Antes de começar, você vai precisar ter instalado em sua máquina as seguintes ferramentas:

- [Git](https://git-scm.com)
- [G++](https://gcc.gnu.org/)

Além disto é bom ter um editor para trabalhar com o código como [VSCode](https://code.visualstudio.com/) ou [Falcon C++](https://www.falconcpp.com/)

## Rodando o projeto

O projeto pode ser executado pelo terminal da seguinte forma:

```bash
# Clone este repositório
$ git clone git@github.com:WillianBL99/AED-ARVORE_DE_BUSCA.git

# Acesse a pasta do projeto no terminal/cmd
$ cd AED-ARVORE_DE_BUSCA

# Compile o arquivo main.cpp
$ g++ main.cpp -o main
# ou o arquivo funcionarios.cpp
$ g++ funcionarios.cpp -o funcionarios

# Execute o arquivo main.exe
$ main
# ou o arquivo funcionarios.exe
$ funcionarios
```
Ou se preferir, pode executar o arquivo diretamente do seu editor de código preferido.

## Funcionalidades do main.cpp

O arquivo main.cpp disponibiliza apenas a visualização de alguns tipos de arvores binárias de busca desenhadas no terminal. Mas internamente, possui as seguintes funções:

- Criar uma árvore binária de busca `Arvore* inicializaArvore(Arvore*)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct Arvore*` e retorna um ponteiro do tipo `struct Arvore*` já alocado na memória.
- Criar um nó `No* criaNo(int)`:
  - Que recebe como parâmetro um inteiro e retorna um ponteiro do tipo `struct No*` já alocado na memória.
- Inserir um nó na árvore `void inserir(Arvore*, int)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct Arvore*` e um inteiro e não retorna nada. Internamente, a função cria um nó com o valor passado como parâmetro e insere na árvore, respeitando a propriedade de que todos os nós à esquerda de um nó são menores que ele e todos os nós à direita são maiores que ele.
- Inserir valores pré-definidos na árvore `void inserirValores(Arvore*, string)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct Arvore*` e uma string que pode ser "cheia", "completa", "zigzag" ou "zigzag1" e não retorna nada. Internamente, a função cria uma árvore binária de busca com os valores pré-definidos de acordo com a string passada como parâmetro.
- Exibir a árvore binária de busca `void exibirArvore(Arvore*, int = 0)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct Arvore*` e um inteiro opcional e não retorna nada. Internamente, a função exibe a árvore binária de busca no terminal, desenhando-a de forma recursiva com o tipo de varredura em-ordem invertida.
- Remover um nó da árvore `No *removeNo(Arvore*, int)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct Arvore*` e um inteiro e retorna um ponteiro do tipo `struct No*`. Internamente, a função remove um nó da árvore binária de busca com o valor passado como parâmetro e retorna o nó removido ou `NULL` caso o nó não exista na árvore.
- Liberar todos os nós da árvore `void liberar(No*)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct No*` e não retorna nada. Internamente, a função percorre a árvore com a varredura pós-ordem e libera todos os nós da árvore.
- Liberar a árvore `void liberarArvore(Arvore*)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct Arvore*` e não retorna nada. Internamente, a função seta a raiz da árvore para `NULL` e chama a função `liberar(No*)` passando a raiz da árvore como parâmetro.

## Funcionalidades do funcionarios.cpp

O arquivo funcionarios.cpp disponibiliza o que seria uma aplicação real de uma árvore binária de busca. O programa permite que o usuário cadastre funcionários, cadastre funcionários aleatórios, exiba todos os funcionários cadastrados, remova um funcionário exibir a quantidade de funcionários cadastrados e liberar todos os funcionários cadastrados. Mas internamente, possui as seguintes funções:

- Retonar a opção escolhida pelo usuário `int opcoes()`:
  - Que não recebe parâmetro e retorna um inteiro. Internamente, a função exibe as opções do menu e retorna a opção escolhida pelo usuário.
- Lidar com a opção escolhida pelo usuário `void menu(int, Arvore*, bool*)`:
  - Que recebe como parâmetro um inteiro, que é a opção escolhida pelo usuário, um ponteiro do tipo `struct Arvore*` e um ponteiro do tipo `bool*`, que é alterado internamente caso o usuário queira sair do programa. Internamente, a função lida com a opção escolhida pelo usuário, chamando as funções necessárias para cada opção.
- Verificar se é null `bool ehNull(No*)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct No*` e retorna um booleano. Internamente, a função verifica se o ponteiro passado como parâmetro é `NULL` e retorna `true` caso seja `NULL` e `false` caso contrário.
- Inicializar a árvore `Arvore* inicializaArvore()`:
  - Que cria e inicializa um ponteiro do tipo `struct Arvore*` e retorna um ponteiro do tipo `struct Arvore*` já alocado na memória e com a quantidade de nós igual a 0.
- Receber os valores para cadastro de um funcinário `Pessoa* getDadosPessoa()`:
  - Que não recebe parâmetro e retorna um ponteiro do tipo `struct Pessoa*`. Internamente, a função recebe os dados de um funcionário e retorna um ponteiro do tipo `struct Pessoa*` já alocado na memória.
- Inserir um funcionário na árvore `void insereFuncionario(Arvore*, Pessoa*)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct Arvore*` e um ponteiro do tipo `struct Pessoa*` que foi previamente preenchido com os dados de um funcionário e não retorna nada. Internamente, a função insere um funcionário na árvore binária de busca.
- Gerar numero de CPF aleatório `string gerarCPF()`:
  - Que não recebe parâmetro e retorna uma string. Internamente, a função gera um número de CPF aleatório não válido e retorna uma string com o número de CPF gerado.
- Gerar nome aleatório `string gerarNome()`:
  - Que não recebe parâmetro e retorna uma string. Internamente, a função gera um nome aleatório e retorna uma string com o nome gerado.
- Gerar idade aleatória `int gerarIdade()`:
  - Que não recebe parâmetro e retorna um inteiro. Internamente, a função gera uma idade aleatória e retorna um inteiro com a idade gerada.
- Gerar salário aleatório `float gerarSalario()`:
  - Que não recebe parâmetro e retorna um float. Internamente, a função gera um salário aleatório e retorna um float com o salário gerado.
- Inserir funcionários aleatórios na árvore `void insereFuncionariosAleatorios(Arvore*, int)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct Arvore*` e um inteiro que representa a quantidade de funcionários aleatórios que serão inseridos na árvore e não retorna nada. Internamente, a função cria funcionarios a partir dos dados aleatórios gerados pelas funções `gerarCPF()`, `gerarNome()`, `gerarIdade()` e `gerarSalario()` e insere na árvore.
- Buscar funcionário na árvore `No* buscaFuncionario(Arvore*, string)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct Arvore*` e uma string que representa o CPF do funcionário que será buscado na árvore e retorna um ponteiro do tipo `struct No*`. Internamente, a função busca um funcionário na árvore e retorna um ponteiro do tipo `struct No*` que aponta para o nó que contém o funcionário buscado.
- Remover funcionário da árvore `void removeFuncionario(Arvore*, string)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct Arvore*` e uma string que representa o CPF do funcionário que será removido da árvore e não retorna nada. Internamente, a função remove um funcionário da árvore.
- Liberar todos os nós da árvore `void libera(No*)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct No*` e não retorna nada. Internamente, a função percorre a árvore com a varredura pós-ordem e libera todos os nós da árvore.
- Liberar arvore `void liberaArvore(Arvore*)`:
  - Que recebe como parâmetro um ponteiro do tipo `struct Arvore*` e não retorna nada. Internamente, a função seta a raiz da árvore para `NULL` e chama a função `libera(No*)` passando a raiz da árvore como parâmetro.

# Autores e contribuidores
- Eric Meira
- Jeová Cosme de Jesus Pinheiro
- Paulo Uilian Barros Lago