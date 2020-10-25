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
    int main()
    {
        ArvoreBinaria arvoreBinaria;
        char comando;
        while (cin>>comando)
        {
            if (comando == 'i')
            {
                string s1;
                cin >> s1;
                Inserir(arvoreBinaria, s1);
            }
            else if(comando!='i'){
                arvoreBinaria.Caminha();
            
            if (comando == 'e')
            {
                int n{};
                cin>>n;
                vector<string> palavras;
                for (int i = 0; i < n; i++)
                {
                    string s1;
                    cin >> s1;
                    palavras.push_back(s1);
                }
                Encripitar(arvoreBinaria, palavras);
            }
            else if (comando == 'd')
            {
                int n{};
                cin >> n;
                vector<int> chaves;
                for (int i = 0; i < n; i++)
                {
                    int c{};
                    cin >> c;
                    chaves.push_back(c);
                }
                Desencripitar(arvoreBinaria, chaves);
            }
            else if (comando == 's')
            {
                string s1;
                cin >> s1;
            }
            }
        };

        return 0;
    }
    void Inserir(ArvoreBinaria & arvoreBinaria, string s)
    {
        TipoItem item;
        item.SetPalavra(s);
        arvoreBinaria.Insere(item);
        //arvoreBinaria.Caminha();
    }
    void Encripitar(ArvoreBinaria arvoreBinaria, vector<string> palavras)
    {
        cout<<"Encriptando...\n";
        for (auto palavra : palavras)
        {
            cout << arvoreBinaria.Pesquisa(palavra).GetChave() << " ";
        }
    }
    void Desencripitar(ArvoreBinaria arvoreBinaria, vector<int> chaves)
    {
        cout<<"Desencriptando...\n";
        for (auto chave : chaves)
        {
            cout << arvoreBinaria.Pesquisa(chave).GetPalavra() << " ";
        }
    }