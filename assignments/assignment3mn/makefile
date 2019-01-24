run: myprogram.o lpt.o johnson.o generate.o ratio.o
	gcc -o run myprogram.o lpt.o johnson.o generate.o ratio.o

myprogram.o: mp.h lpt.h johnson.h generate.h ratio.h 
	gcc -c myprogram.c

lpt.o: lpt.c lpt.h
	gcc -c lpt.c

johnson.o: johnson.c johnson.h
	gcc -c johnson.c

generate.o: generate.c generate.h
	gcc -c generate.c

ratio.o: ratio.c ratio.h
	gcc -c ratio.c

