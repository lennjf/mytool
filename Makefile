

main: main.c
	gcc main.c -o main

mytool: mytool.c
	gcc -c mytool.c -o mytool.o
	ar rcs libmytool.a mytool.o
