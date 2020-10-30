#include <iostream>
#include <vector>
#include "ArvoreBinaria.h"
#include "Node.h"
#include "TipoItem.h"
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;
void Inserir(ArvoreBinaria &arvoreBinaria, string s);
void Encriptar(ArvoreBinaria &arvoreBinaria, vector<string> palavras);
void Desencriptar(ArvoreBinaria &arvoreBinaria, vector<int> chaves);
void Substituir(ArvoreBinaria &arvoreBinaria, string &s1, string &s2);
int main(){
    ArvoreBinaria arvoreBinaria;
    char comando;
    while (cin>>comando){
        if (comando == 'i'){
            string s1;
            cin >> s1;
            Inserir(arvoreBinaria, s1);
        }
    
        if (comando == 'e'){
            int k{};
            cin>>k;
            vector<string> palavras;
            for (int i = 0; i < k; i++){
                string s1;
                cin >> s1;
                palavras.push_back(s1);
            }
            Encriptar(arvoreBinaria, palavras);
        }
        else if (comando == 'd'){
            int k{};
            cin >> k;
            vector<int> chaves;
            for (int i = 0; i < k; i++){
                int c{};
                cin >> c;
                chaves.push_back(c);
            }
            Desencriptar(arvoreBinaria, chaves);
        }
        else if (comando == 's'){
            string s1,s2;
            cin >> s1>>s2;
            Substituir(arvoreBinaria,s1,s2);
        }
        
    };

    return 0;
}
void Inserir(ArvoreBinaria &arvoreBinaria, string s){
    TipoItem item;
    item.SetPalavra(s);
    arvoreBinaria.Insere(item);
    arvoreBinaria.Caminha(); //função para setar as chaves das palavras
}
void Encriptar(ArvoreBinaria &arvoreBinaria, vector<string> palavras){
    cout << endl;
    for (auto palavra : palavras){
        cout << arvoreBinaria.Pesquisa(palavra).GetChave() << " ";
    }
    cout << endl;
}
void Desencriptar(ArvoreBinaria &arvoreBinaria, vector<int> chaves){
    for (auto chave : chaves){
        arvoreBinaria.Desencriptando(chave);
        
    }
    cout<<endl;
}
void Substituir(ArvoreBinaria &arvoreBinaria, string &s1, string &s2){
    arvoreBinaria.Substituindo(s1, s2);
    arvoreBinaria.Caminha(); //arrumando as chaves após a substituição
}