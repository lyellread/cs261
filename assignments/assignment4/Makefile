default: prog 

avl.o: avl.c avl.h 
	gcc -Wall -ansi -pedantic-errors -c avl.c

prog: avl.o main.c
	gcc -Wall -ansi -pedantic-errors -o prog avl.o  main.c

clean:
	rm avl.o	

cleanall: clean
	rm prog
