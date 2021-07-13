all: add-nbo

add-nbo: add-nbo.o
	gcc add-nbo.o -o add-nbo
	rm *.o

add-nbo.o: add-nbo.c
	gcc -c add-nbo.c -o add-nbo.o

clean:
	rm add-nbo *.o
