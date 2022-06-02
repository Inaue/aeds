
all: exercicio_pilha exercicio_lista clean

exercicio_pilha: mainP.o pilhas.o
	gcc mainP.o pilhas.o -o exercicio_pilha

exercicio_lista: mainL.o lista.o
	gcc mainL.o lista.o -o exercicio_lista

mainP.o: mainP.c
	gcc -c mainP.c

mainL.o: mainL.c
	gcc -c mainL.c

pilhas.o: pilhas.c pilhas.h
	gcc -c pilhas.c

lista.o: lista.c lista.h
	gcc -c lista.c

clean:
	rm -r *.o
