#include "ArvoreBinaria.h"
ArvoreBinaria::ArvoreBinaria(){
    raiz = nullptr;
}
ArvoreBinaria::~ArvoreBinaria(){
    Limpa();
}
void ArvoreBinaria::Insere(TipoItem item){
    InsereRecursivo(raiz, item);
}
void ArvoreBinaria::InsereRecursivo(Node *&p, TipoItem item){
    if (p == nullptr){
        p = new Node();
        p->item = item;
    }
    else{
        if (item.GetPalavra() < p->item.GetPalavra())
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}
void ArvoreBinaria::Antecessor(Node *q, Node *&r){
    if (r->dir != nullptr){
        Antecessor(q, r->dir);
        return;
    }
    q->item = r->item;
    q = r;
    r = r->esq;
    free(q);
}
void ArvoreBinaria::RemoveRecursivo(Node *&no, std::string palavra){
    Node *aux;
    if (no == nullptr){
        throw "Item nao está presente";
    }
    if (palavra < no->item.GetPalavra())
        return RemoveRecursivo(no->esq, palavra);
    else if (palavra > no->item.GetPalavra())
        return RemoveRecursivo(no->dir, palavra);
    else{
        if (no->dir == nullptr){
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if (no->esq == nullptr){
            aux = no;
            no = no->dir;
            free(aux);
        }
        else
            Antecessor(no, no->esq);
    }
}
void ArvoreBinaria::Remove(std::string palavra){
    RemoveRecursivo(raiz, palavra);
}
TipoItem ArvoreBinaria::Pesquisa(std::string palavra){
    return PesquisaRecursivo(raiz, palavra);
}
TipoItem ArvoreBinaria::PesquisaRecursivo(Node *no, std::string palavra){
    TipoItem aux;
    if (no == nullptr){
        aux.SetChave(-1); // Flag para item não presente
        return aux;
        free(no);
    }
    if (palavra < no->item.GetPalavra())
        return PesquisaRecursivo(no->esq, palavra);
    else if (palavra > no->item.GetPalavra())
        return PesquisaRecursivo(no->dir, palavra);
    else
        return no->item;
}
void ArvoreBinaria::Substituindo(std::string &palavra1, std::string &palavra2){
    Remove(palavra1);
    TipoItem item;
    item.SetPalavra(palavra2);
    Insere(item);
}
void ArvoreBinaria::Caminha(){
    Node *p = raiz;
    int chave = 1;
    PreOrdemChave(p,chave);
}
void ArvoreBinaria::PreOrdemChave(Node *p,int &chave){   
    if (p != nullptr){   
        p->item.SetChave(chave);
        chave++;
        PreOrdemChave(p->esq,chave);
        PreOrdemChave(p->dir,chave);
    }
}
void ArvoreBinaria::PreOrdemPalavra(Node *p,int &chave){
    if (p != nullptr){
        if(chave==p->item.GetChave()){
        p->item.ImprimePalavra();        
        }
        PreOrdemPalavra(p->esq, chave);
        PreOrdemPalavra(p->dir, chave);
    }
}
void ArvoreBinaria::Desencriptando(int chave){
    PreOrdemPalavra(raiz, chave);
}
void ArvoreBinaria::Limpa(){
    ApagaRecursivo(raiz);
    raiz = nullptr;
}
void ArvoreBinaria::ApagaRecursivo(Node *p){
    if (p != nullptr){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}