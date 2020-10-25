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
void Encripitar(ArvoreBinaria arvoreBinaria, vector<string> palavras);
void Desencripitar(ArvoreBinaria arvoreBinaria, vector<int> chaves);
void Substituir(ArvoreBinaria &arvoreBinaria, string s1, string s2);
int main(){
    ArvoreBinaria arvoreBinaria;
    char comando;
    while (cin>>comando){
        if (comando == 'i'){
            string s1;
            cin >> s1;
            Inserir(arvoreBinaria, s1);
        }
        else {
            //arvoreBinaria.Caminha();
            if (comando == 'e'){
                int n{};
                cin>>n;
                vector<string> palavras;
                for (int i = 0; i < n; i++){
                    string s1;
                    cin >> s1;
                    palavras.push_back(s1);
                }
                Encripitar(arvoreBinaria, palavras);
            }
            else if (comando == 'd'){
                int n{};
                cin >> n;
                vector<int> chaves;
                for (int i = 0; i < n; i++){
                    int c{};
                    cin >> c;
                    chaves.push_back(c);
                }
                for(auto chave : chaves){
                    cout<<"\n"<<chave<<" ";
                }
                cout<<endl;
                Desencripitar(arvoreBinaria, chaves);
            }
            else if (comando == 's'){
                string s1,s2;
                cin >> s1>>s2;
                Substituir(arvoreBinaria,s1,s2);
            }
        }
    };

    return 0;
}
void Inserir(ArvoreBinaria & arvoreBinaria, string s){
    TipoItem item;
    item.SetPalavra(s);
    arvoreBinaria.Insere(item);
    arvoreBinaria.Caminha();
}
void Encripitar(ArvoreBinaria arvoreBinaria, vector<string> palavras){
    //cout<<"Encriptando...\n";
    cout << endl;
    for (auto palavra : palavras){
        cout << arvoreBinaria.PesquisaP(palavra).GetChave() << " ";
    }
    cout << endl;
}
void Desencripitar(ArvoreBinaria arvoreBinaria, vector<int> chaves){
    //cout<<"Desencriptando...\n";
    cout<<endl;
    for (auto chave : chaves){
        cout << arvoreBinaria.PesquisaC(chave).GetPalavra() << " ";
        
    }
    cout<<endl;
    cout << arvoreBinaria.PesquisaC(2).GetPalavra() << " ";
    cout << arvoreBinaria.PesquisaC(3).GetPalavra() << " ";
    cout << arvoreBinaria.PesquisaC(5).GetPalavra() << " ";
    cout << arvoreBinaria.PesquisaC(7).GetPalavra() << " "<<endl;
}
void Substituir(ArvoreBinaria &arvoreBinaria, string s1, string s2){
    int chave{};
    chave = arvoreBinaria.PesquisaP(s1).GetChave();
    arvoreBinaria.Remove(chave);
    TipoItem item;
    item.SetPalavra(s2);
    arvoreBinaria.Insere(item);
    arvoreBinaria.Caminha();
}