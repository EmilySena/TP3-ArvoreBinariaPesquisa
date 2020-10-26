# Emily Oliveira Sena
#TP3 - Estrututa de Dados

CC=g++ 
CFLAGS=-Wall -Wextra
EXEC=./tp3 
TMPOUT=tp3.testresult

$(EXEC): main.cpp ArvoreBinaria.o TipoItem.o Node.o
	$(CC) $(CFLAGS) main.cpp ArvoreBinaria.o TipoItem.o Node.o -o $(EXEC)

ArvoreBinaria.o: ArvoreBinaria.cpp
	$(CC) $(CFLAGS) -c ArvoreBinaria.cpp -o ArvoreBinaria.o
TipoItem.o: TipoItem.cpp
	$(CC) $(CFLAGS) -c TipoItem.cpp -o TipoItem.o
Node.o: Node.cpp
	$(CC) $(CFLAGS) -c Node.cpp -o Node.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: 
	rm -rf Node.o
	rm -rf ArvoreBinaria.o
	rm -rf TipoItem.o
	


