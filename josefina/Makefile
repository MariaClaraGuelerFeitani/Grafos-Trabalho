all: compila
compila: main.o busca.o fila.o funcao.o grafo.o
	gcc main.o busca.o fila.o funcao.o grafo.o -o prog
main.o: main.c
	gcc -c main.c
busca.o: busca.c
	gcc -c busca.c
fila.o: fila.c
	gcc -c fila.c
funcao.o: funcao.c
	gcc -c funcao.c
grafo.o: grafo.c
	gcc -c grafo.c 
clean:
	rm -f main.o busca.o fila.o funcao.o grafo.o prog