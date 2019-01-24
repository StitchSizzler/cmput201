run: myprogram.o lpt.o johnson.o read.o generate.o
	gcc -o run myprogram.o lpt.o johnson.o read.o generate.o

myprogram.o: mp.h lpt.h johnson.h read.h generate.h
	gcc -c myprogram.c

lpt.o: lpt.c lpt.h
	gcc -c lpt.c

johnson.o: johnson.c johnson.h
	gcc -c johnson.c

read.o: read.c read.h
	gcc -c read.c

random.o: generate.c generate.h
	gcc -c generate.c


