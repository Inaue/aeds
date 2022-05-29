
all: exercicio_de_fila

exercicio_de_fila: main.o fila.o
	gcc -o exercicio_de_fila main.o fila.o

main.o: main.c fila.h
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic

fila.o: fila.c fila.h
	gcc -o fila.o fila.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o *~ exercicio_de_fila


