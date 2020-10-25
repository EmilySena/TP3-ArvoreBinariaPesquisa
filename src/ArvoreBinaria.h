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
    void Caminha(int tipo);
    void Limpa();

private:
    void InsereRecursivo(Node *&p, TipoItem item);
    void ApagaRecursivo(Node *p);
    void PorNivel();
    void PreOrdem(Node *p);
 /*   void InOrdem(Node *p);
    void PosOrdem(Node *p);
    */
    Node *raiz;
};
#endif // ArvoreBinaria_H