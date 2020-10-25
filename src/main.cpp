#include <iostream>
#include "ArvoreBinaria.h"
#include "Node.h"
#include "TipoItem.h"
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main() {
    ArvoreBinaria arvoreBinaria;
    string s1;
    cin>>s1;
    TipoItem item;
    item.SetPalavra(s1);
    arvoreBinaria.Insere(item);
    cout<<item.GetPalavra()<<endl;
    TipoItem item2;
    item2.SetPalavra("ww0");
    arvoreBinaria.Insere(item2);
    cout<<arvoreBinaria.Pesquisa("www").GetPalavra()<<endl;
    cout<<"------------"<<endl;
    TipoItem item3;
    TipoItem item4;
    item3.SetPalavra("kkkkk");
    arvoreBinaria.Insere(item3);
    item4.SetPalavra("dsfh");
    arvoreBinaria.Insere(item4);
    cout<<"caminhando::\n"<<endl;
    arvoreBinaria.Caminha();
    cout<<item2.GetChave()<<endl;
    cout << arvoreBinaria.Pesquisa("dsfh").GetChave() << endl;
    cout<<"--------------"<<endl;
    arvoreBinaria.Caminha();
    cout<<endl;

    return 0;
}