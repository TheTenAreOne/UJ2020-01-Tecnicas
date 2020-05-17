all: program

program: main funcionesCC
	g++ -o parcialCC main.o funcionesCC.o

funcionesCC: FuncionesCC.cpp FuncionesCC.h
	g++ -c FuncionesCC.cpp

main: Main.cpp FuncionesCC.h
	g++ -c Main.cpp