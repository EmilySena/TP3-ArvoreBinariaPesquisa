#include "TipoItem.h"
#include "Node.h"
#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
class ArvoreBinaria{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(TipoItem item);
    TipoItem PesquisaC(int chave);
    TipoItem PesquisaP(std::string palavra);
    void Remove(int chave);
    void RemoveP(std::string palavra);
    void Caminha();
    void Desencriptando(int chave);
    void Substituindo(std::string &palavra1, std::string &palavra2);
    void Limpa();

private:
    void InsereRecursivo(Node *&p, TipoItem item);
    void ApagaRecursivo(Node *p);
    TipoItem PesquisaRecursivoC(Node* p, int chave);
    TipoItem PesquisaRecursivoP(Node* p, std::string palavra);
    void RemoveRecursivo(Node* &p, int chave);
    void RemovePalavra(Node* &p, std::string palavra);
    void Antecessor(Node* q, Node* &r);
    void PreOrdemChave(Node *p,int &chave);
    void PreOrdemPalavra(Node *p, int &chave);
    /*   
    void InOrdem(Node *p);
    void PosOrdem(Node *p);
    */
    Node *raiz;
};
#endif // ArvoreBinaria_H