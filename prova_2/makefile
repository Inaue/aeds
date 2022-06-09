
all: resolucao clean

resolucao: main.o pilhas.o fila2.o
	gcc main.o pilhas.o fila2.o -o resolucao

pilhas.o: pilhas.c pilhas.h
	gcc -c pilhas.c

fila2.o: fila2.c fila2.h
	gcc -c fila2.c

clean:
	rm -r *.o
