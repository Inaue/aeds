
all: resolucao clean

resolucao: main.o lista.o pilhas.o fila2.o
	gcc main.o lista.o pilhas.o fila2.o -o resolucao

lista.o: lista.c lista.h 
	gcc -c lista.c

pilhas.o: pilhas.c pilhas.h
	gcc -c pilhas.c

fila2.o: fila2.c fila2.h
	gcc -c fila2.c

clean:
	rm -r *.o
