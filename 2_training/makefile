
all: exercicio_pilha exercicio_lista exercicio_fila 

exercicio_pilha: mainP.o pilhas.o
	gcc mainP.o pilhas.o -o exercicio_pilha

exercicio_lista: mainL.o lista.o lista2c.o
	gcc mainL.o lista.o lista2c.o -o exercicio_lista

exercicio_fila:	mainF.o fila.o
	gcc mainF.o fila.o -o exercicio_fila

mainF.o: mainF.c fila.h
	gcc -c mainF.c

mainP.o: mainP.c
	gcc -c mainP.c

mainL.o: mainL.c
	gcc -c mainL.c

pilhas.o: pilhas.c pilhas.h
	gcc -c pilhas.c

lista.o: lista.c lista.h
	gcc -c lista.c

lista2c.o: lista2c.c lista2c.h
	gcc -c lista2c.c

fila.o: fila.c fila.h
	gcc -c fila.c

clean:
	rm -rf *.o *~ exercicio_*
