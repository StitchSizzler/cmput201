sorting: sorting1523147.o bsort.o ssort.o hsort.o msort.o isort.o qsort.o
	gcc -o sorting sorting1523147.o bsort.o ssort.o hsort.o msort.o isort.o qsort.o

sorting1523147.o: sorting1523147.h b.h s.h h.h m.h i.h q.h
	gcc -c sorting1523147.c

bsort.o: bsort.c b.h
	gcc -c bsort.c

ssort.o: ssort.c s.h
	gcc -c ssort.c

hsort.o: hsort.c h.h
	gcc -c hsort.c

msort.o: msort.c m.h
	gcc -c msort.c

isort.o: isort.c i.h
	gcc -c isort.c

qsort.o: qsort.c q.h
	gcc -c qsort.c
