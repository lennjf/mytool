

.PHONY: test clean all

main: main.c
	gcc main.c -o main -L. -lmytool

mytool: mytool.c
	gcc -c mytool.c -o mytool.o
	ar rcs libmytool.a mytool.o

clean:
	rm libmytool.a
