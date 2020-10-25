#include "ArvoreBinaria.h"
ArvoreBinaria::ArvoreBinaria()
{
    raiz = nullptr;
}
ArvoreBinaria::~ArvoreBinaria()
{
    Limpa();
}
void ArvoreBinaria::Insere(TipoItem item)
{
    InsereRecursivo(raiz, item);
}
void ArvoreBinaria::InsereRecursivo(Node *&p, TipoItem item)
{
    if (p == nullptr)
    {
        p = new Node();
        p->item = item;
    }
    else
    {
        if (item.GetChave() < p->item.GetChave())
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}
void ArvoreBinaria::PreOrdem(Node *p)
{
    if (p != nullptr)
    {
        p->item.Imprime();
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}
/*void ArvoreBinaria::InOrdem(Node *p)
{
    if (p != nullptr)
    {
        InOrdem(p->esq);
        p->item.Imprime();
        InOrdem(p->dir);
    }
}
void ArvoreBinaria::PosOrdem(Node *p)
{
    if (p != nullptr)
    {
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        p->item.Imprime();
    }
}
*/
void ArvoreBinaria::Limpa()
{
    ApagaRecursivo(raiz);
    raiz = nullptr;
}
void ArvoreBinaria::ApagaRecursivo(Node *p)
{
    if (p != nullptr)
    {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}