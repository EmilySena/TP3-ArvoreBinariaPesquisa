#include "TipoItem.h"
#include <iostream>
TipoItem::TipoItem(){
    Palavra="";
    Chave=0;

}
TipoItem::TipoItem(int chave){
    Chave = chave;
}
TipoItem::TipoItem(std::string palavra){
    Palavra = palavra;
}
TipoItem::TipoItem(std::string palavra, int chave){
    Chave = chave;
    Palavra = palavra;
}
TipoItem::~TipoItem(){

}
std::string TipoItem::GetPalavra(){
    return Palavra;
}
void TipoItem::SetPalavra(std::string palavra){
    Palavra = palavra;
}
int TipoItem::GetChave(){
    return Chave;
}
void TipoItem::SetChave(int chave){
    Chave = chave;
}
void TipoItem::ImprimeChave(){
    std::cout<<Chave<<" ";
}
void TipoItem::ImprimePalavra(){
    std::cout<<Palavra<<" ";
}

