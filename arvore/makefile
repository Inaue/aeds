
all: exercicio_de_arvore 

exercicio_de_arvore: main.o arvore.o
	gcc -o exercicio_de_arvore main.o arvore.o

main.o: main.c arvore.h
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic

arvore.o: arvore.c arvore.h
	gcc -o arvore.o arvore.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o


