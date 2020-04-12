all: program

program: main funcionesCC
	gcc -o parcialCC main.o funcionesCC.o

funcionesCC: FuncionesCC.c FuncionesCC.h
	gcc -c FuncionesCC.c

main: Main.c FuncionesCC.h
	gcc -c Main.c