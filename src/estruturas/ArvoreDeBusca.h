#include <cstddef>
#include <iostream>

/*
 A classe Aluno será utilizada na árvore de busca. Colocaremos com
 maior prioridade os alunos com RA mais alto.
*/

class Aluno{
 public:

  Aluno(){
    this->ra   = -1;
    this->nome = "";
  };

  Aluno(int ra, std::string nome){
    this->ra    = ra;
    this->nome  = nome;
  }

  std::string getNome() const {
    return nome;
  }

  int getRa() const{
    return ra;
  }

 private :
  int         ra;
  std::string nome;
};

/*
  Nós poderíamos ter colocado os filhos à esquerda e à direita
  diretamente na classe Aluno, mas eu prefiro criar uma separação
  maior entre a estrutura da árvore e o contéudo.
 */

struct NodeAluno
{
  Aluno      aluno;
  NodeAluno* esquerda;
  NodeAluno* direita;
};


/*
  A classe ArvoreDeBusca é a que irá gerenciar todas as funções da árvore
  de busca. Você notará que essa árvore foi implementada com várias
  funções recursivas privadas e várias funções públicas que
  simplesmente invocam as funções privadas e fornecem algum valor para
  o parâmetro como ponto de partida.
 */
class ArvoreDeBusca
{

 public:  
  ArvoreDeBusca() {
    root = NULL;
  }
    
  ~ArvoreDeBusca(){
   destroyTree(root);
  }

  // Este método já está implementado e só invoca o método privado
  // recursivo. Você deverá implementar o método recursivo.
  void printTree() const
  {
    printTree(root);
  }
  
  // Verifica se a árvore possui pelo menos um nó. Você precisa ainda
  // implementar este método.
  bool isEmpty() const;

  // Verifica se é possível alocar um novo nó. Você usará a mesma
  // estratégia de LinkedQueue e LinkeStack.
  bool isFull() const
  {
      NodeAluno* location;
      try
      {
          location = new NodeAluno;
          delete location;
          return false;
      }
      catch(std::bad_alloc exception)
      {
          return true;
      }
  };

/* Todos os métodos públicos abaixo já estão implementados, note que
   eles simplesmente invocam métodos recursivos configurando os
   valores iniciais. Você deverá se preocupar apenas com os métodos
   privados que implementam a funcionalidade invocada por esses
   métodos públicos. */
  
  void retrieveAluno(Aluno& item, bool& found) const
  {
    retrieveAluno(root, item, found);
  }

  void insertAluno(Aluno item){
    insertAluno(root, item);
  }
  
  void deleteAluno(Aluno item){
    deleteAluno(root, item);
  }


 private:

  /* 
    Funções recursivas que serão usadas por algumas das funções
     públicas.

     O construtor dessa classe invocará destroyTree que você precisa
   implementar. Em resumo, você devera caminhar pela árvore apagando
   todos os nós que existem. Cuidado com a ordem em que você faz a
   chamada ao delete. Garanta que só invocará o comando delete após
   ambos os filhos terem sido removidos.*/

  void destroyTree(NodeAluno*& tree);

  /*
   O metodo público chamado de retrieveAluno irá fazer uma chamada
   para este método. Implemente este método de forma recursiva. Para
   isso que serve o primeiro parâmetro NodeAluno *tree.
  
   Você vai receber um objeto "item" que será usado como chave. Após
   isso, você tera que procurar se na árvore existe algum nó com essa
   chave. Se existir, então você coloca em "item" (no próprio
   parâmetro) o objeto que estava no nó da sua árvore.

   Use a variável "found" para avisar a quem chamou se o objeto "item"
   foi alterado ou não. Em outras palavras, avise em "found" se o nó
   existe ou não.
  */
  
  void retrieveAluno(NodeAluno* tree, Aluno& item, bool& found) const
  {
      if (tree == NULL)
          found = false;
      else if (aluno.getRa() < tree->aluno.getRa())
          retrieveAluno(tree->esquerda, aluno, found);
      else if (aluno.getRa() > tree->aluno.getRa())
          retrieveAluno(tree->direita, aluno, found);
      else {
          aluno = tree->aluno;
          found = true;
      }
      }
  };

  // De forma análoga, os métodos abaixo deverão ser chamados pelos
  // métodos públicos. Os parâmetros NodeAluno*& tree estão ai para
  // você implementar este método de forma recursiva.
  void insertAluno(NodeAluno*& tree, Aluno item);

  // Use este método privado apenas para navegar pela arvore até
  // encontrar o nó que voce deseja excluir. Feito isso, chame o
  // método deleteNodeAluno passando como parâmetro o nó que você
  // encontrou.
  void deleteAluno(NodeAluno*& tree, Aluno item);

  // Nesse método, você receberá como parâmetro o nó que precisa ser
  // removido. Observe que temos três casos: (i) o nó pode ser uma
  // folha, (ii) o nó pode ter um filho e (iii) o nó pode ter dois
  // filhos. Caso o nó tenha dois filhos, você deverá chamar o método
  // getSuccessor para obter o nó que deverá substituir o nó atual
  // antes da remoção.
  void deleteNodeAluno(NodeAluno*& tree); 

  // Procure o sucessor do nó atual na árvore. Em outras palavras,
  // procure o nó mais à esquerda da arvore da direita.
  void getSuccessor(NodeAluno* tree, Aluno& data);


  void printTree(NodeAluno *tree) const
  {
    std::cout << "Pre:  ";
    printPreOrder(tree);
    std::cout << std::endl;
    std::cout << "In:   ";
    printInOrder(tree);
    std::cout << std::endl;
    std::cout << "Post: ";
    printPostOrder(tree);
    std::cout << std::endl;
  }
  
  void printPreOrder(NodeAluno* tree)  const;
  void printInOrder(NodeAluno* tree)   const;
  void printPostOrder(NodeAluno* tree) const;
  
  // Nossa estrutura de dados. Raiz da árvore binaria de busca.
  NodeAluno* root;
};
