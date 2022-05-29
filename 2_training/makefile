
all: treinamento

treinamento: main.o fila.o lista.o pilhas.o
	gcc -o treinamento main.o fila.o lista.o pilhas.o

main.o: main.c fila.h
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic

fila.o: fila.c fila.h
	gcc -o fila.o fila.c -c -W -Wall -ansi -pedantic

lista.o: lista.c lista.h
	gcc -o lista.o lista.c -c -W -Wall -ansi -pedantic

pilhas.o: pilhas.c pilhas.h
	gcc -o pilhas.o pilhas.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o *~ treinamento


