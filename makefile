all : isort txtfind

isort : mainSort.o isort.o
	gcc -Wall -g -o isort mainSort.o isort.o

mainSort.o : mainSort.c isort.h
	gcc -Wall -g -c mainSort.c

isort.o : isort.c isort.h
	gcc -Wall -g -c isort.c	

txtfind : mainTxtfind.o txtfind.o
	gcc -Wall -g -o txtfind mainTxtfind.o txtfind.o

mainTxtfind.o : mainTxtfind.c txtfind.h
	gcc -Wall -g -c mainTxtfind.c

txtfind.o : txtfind.c txtfind.h	
	gcc -Wall -g -c txtfind.c

clean : 
	rm -f *.o isort txtfind