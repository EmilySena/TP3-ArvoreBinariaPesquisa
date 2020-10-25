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
        if (item.GetPalavra() < p->item.GetPalavra())
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}
void ArvoreBinaria::Remove(int chave)
{
    return RemoveRecursivo(raiz, chave);
}
void ArvoreBinaria::Antecessor(Node *q, Node *&r)
{
    if (r->dir != NULL)
    {
        Antecessor(q, r->dir);
        return;
    }
    q->item = r->item;
    q = r;
    r = r->esq;
    free(q);
}
void ArvoreBinaria::RemoveRecursivo(Node *&no, int chave)
{
    Node *aux;
    if (no == NULL)
    {
        throw("Item nao está presente");
    }
    if (chave < no->item.GetChave())
        return RemoveRecursivo(no->esq, chave);
    else if (chave > no->item.GetChave())
        return RemoveRecursivo(no->dir, chave);
    else
    {
        if (no->dir == NULL)
        {
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if (no->esq == NULL)
        {
            aux = no;
            no = no->dir;
            free(aux);
        }
        else
            Antecessor(no, no->esq);
    }
}
TipoItem ArvoreBinaria::Pesquisa(int chave)
{
    return PesquisaRecursivo(raiz, chave);
}
TipoItem ArvoreBinaria::Pesquisa(std::string palavra)
{
    return PesquisaRecursivo(raiz, palavra);
}
TipoItem ArvoreBinaria::PesquisaRecursivo(Node *no, int chave)
{
    TipoItem aux;
    if (no == nullptr)
    {
        aux.SetChave(-1); // Flag para item não presente
        return aux;
    }
    if (chave < no->item.GetChave())
        return PesquisaRecursivo(no->esq, chave);
    else if (chave > no->item.GetChave())
        return PesquisaRecursivo(no->dir, chave);
    else
        return no->item;
}
TipoItem ArvoreBinaria::PesquisaRecursivo(Node *no, std::string palavra)
{
    TipoItem aux;
    if (no == nullptr)
    {
        aux.SetChave(-1); // Flag para item não presente
        return aux;
    }
    if (palavra < no->item.GetPalavra())
        return PesquisaRecursivo(no->esq, palavra);
    else if (palavra > no->item.GetPalavra())
        return PesquisaRecursivo(no->dir, palavra);
    else
        return no->item;
}
void ArvoreBinaria::Caminha(){
    Node *p = raiz;
    int chave = 1;
    PreOrdemChave(p,chave);
}
void ArvoreBinaria::PreOrdemChave(Node *p, int chave)
{
    if (p != nullptr)
    {   
        p->item.SetChave(chave);
        chave++;
        p->item.ImprimeChave();
        PreOrdemChave(p->esq,chave);
        PreOrdemChave(p->dir,chave);
    }
}
void ArvoreBinaria::PreOrdemPalavra(Node *p)
{
    if (p != nullptr)
    {
        p->item.ImprimePalavra();
        PreOrdemPalavra(p->esq);
        PreOrdemPalavra(p->dir);
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