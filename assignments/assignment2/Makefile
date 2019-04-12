default: prog

dynArray.o: dynArray.c dynArray.h 
	gcc -Wall -ansi -c dynArray.c	

prog: dynArray.o
	gcc -Wall -ansi -o prog dynArray.o stackapp.c

b2s: dynArray.o
	gcc -Wall -ansi -o b2s dynArray.o bag2set.c
		
clean:
	rm dynArray.o

cleanall: clean
	rm *.o