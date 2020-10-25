#include "TipoItem.h"
#include "Node.h"
#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(TipoItem item);
    TipoItem Pesquisa(int chave);
    TipoItem Pesquisa(std::string palavra);
    void Remove(int chave);
    void Caminha();
    void Limpa();

private:
    void InsereRecursivo(Node *&p, TipoItem item);
    void ApagaRecursivo(Node *p);
    TipoItem PesquisaRecursivo(Node* p, int chave);
    TipoItem PesquisaRecursivo(Node* p, std::string palavra);
    void RemoveRecursivo(Node* &p, int chave);
    void Antecessor(Node* q, Node* &r);
    void PreOrdemChave(Node *p,int &chave);
    void PreOrdemPalavra(Node *p);
    /*   
    void InOrdem(Node *p);
    void PosOrdem(Node *p);
    */
    Node *raiz;
};
#endif // ArvoreBinaria_H