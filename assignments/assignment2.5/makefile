run: myprogram.o lpt.o johnson.o
	gcc -o run myprogram.o lpt.o johnson.o

myprogram.o: mp.h lpt.h johnson.h
	gcc -c myprogram.c

lpt.o: lpt.c lpt.h
	gcc -c lpt.c

johnson.o: johnson.c johnson.h
	gcc -c johnson.c


