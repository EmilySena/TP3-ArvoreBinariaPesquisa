# TP3-ArvoreBinariaPesquisa
TP da disciplina de Estrutura de Dados do DCC.
O objetivo desse trabalho era implementar uma árvore binária de pesquisa que servisse como dicionário de uma língua, onde seriam armazenadas as palavras e cada palavra estaria associada a uma chave que é um número inteiro.
As operções realizadas são: 
-Inserção de nova palavra, que acrescenta uma nova palavra no dicionário
-Encriptação: recebe uma frase e encripta ela, associando as palavras as chaves delas, e devolvendo a frase encriptada como números.
-Decreptação: recebe números e devolve as palavras que são associadas a esses números
-Substituição: recebe uma palavra que já está no dicionário e troca por uma outra palavra que é informada.
Para compilar, esse projeto:
git clone https://github.com/EmilySena/TP3-ArvoreBinariaPesquisa/
depois abra o src no terminal e digite make
para compilar ./tp3
para fazer os testes: make test
para apagar os .o gerados, make clean
