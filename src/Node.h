#include "TipoItem.h"
#ifndef NODE_H
#define NODE_H
class Node
{
public:
    Node();

private:
    TipoItem item;
    Node *esq;
    Node *dir;
    friend class ArvoreBinaria;
};
#endif // Node_H