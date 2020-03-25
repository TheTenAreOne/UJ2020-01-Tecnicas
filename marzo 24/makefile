all: program

program: main calendario
	gcc -o marzo24_G4 main.o calendario.o
	
calendario: calendario.c calendario.h
	gcc -c calendario.c

main: main.c calendario.h
	gcc -c main.c