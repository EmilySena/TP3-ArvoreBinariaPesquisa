#include <string>
#ifndef TIPOITEM_H
#define TIPOITEM_H
class TipoItem {
    private:
    std::string Palavra;
    int Chave;

    public:
    TipoItem();
    TipoItem(int chave);
    TipoItem(std::string palavra);
    TipoItem(std::string palavra, int chave);
    virtual ~TipoItem();
    std::string GetPalavra();
    int GetChave();
    void SetPalavra(std::string palavra);
    void SetChave(int chave);
    void ImprimeChave();
    void ImprimePalavra();


};
#endif // TIPOITEM_H