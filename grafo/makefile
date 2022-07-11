
all: exercicio_1 exercicio_2 exercicio_3

exercicio_1: ex1.o 
	gcc -o exercicio_1 ex1.o 

exercicio_2: ex2.o lista.o 
	gcc -o exercicio_2 ex2.o lista.o

exercicio_3: ex3.o 
	gcc -o exercicio_3 ex3.o 

ex1.o: ex1.c 
	gcc -c ex1.c

ex2.o: ex2.c lista.h 
	gcc -c ex2.c

ex3.o: ex3.c 
	gcc -c ex3.c 

lista.o: lista.c lista.h
	gcc -c lista.c

clean:
	rm -rf *.o exercicio_1 exercicio_2 exercicio_3


