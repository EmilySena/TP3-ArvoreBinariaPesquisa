#include "TipoItem.h"
#include "Node.h"
#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
class ArvoreBinaria{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(TipoItem item);
    TipoItem Pesquisa(std::string palavra);
    void Remove(std::string palavra);
    void Caminha();
    void Desencriptando(int chave);
    void Substituindo(std::string &palavra1, std::string &palavra2);
    void Limpa();

private:
    void InsereRecursivo(Node *&p, TipoItem item);
    void ApagaRecursivo(Node *p);
    TipoItem PesquisaRecursivo(Node* p, std::string palavra);
    void RemoveRecursivo(Node* &p, std::string palavra);
    void Antecessor(Node* q, Node* &r);
    void PreOrdemChave(Node *p,int &chave);
    void PreOrdemPalavra(Node *p, int &chave);
    Node *raiz;
};
#endif // ArvoreBinaria_H