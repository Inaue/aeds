
all: exercicio_1 exercicio_2 exercicio_3

exercicio_1: ex1.o 
	gcc -o exercicio_1 ex1.o 

exercicio_2: ex1.o 
	gcc -o exercicio_2 ex2.o 

exercicio_3: ex1.o 
	gcc -o exercicio_3 ex3.o 

ex1.o: ex1.c 
	gcc -o ex1.o ex1.c -c -W -Wall -ansi -pedantic

ex2.o: ex2.c 
	gcc -o ex2.o ex2.c -c -W -Wall -ansi -pedantic

ex3.o: ex3.c 
	gcc -o ex3.o ex3.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o exercicio_1 exercicio_2 exercicio_3


