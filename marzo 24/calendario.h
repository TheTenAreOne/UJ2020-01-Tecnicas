#include <stdio.h>
#include <string.h>

enum meses{
	NOVIEMBRE = 11, 
	DICIEMBRE = 12
};  //Solo se usan estos 2 meses pues son casos especiales para la funcion crearPersona

typedef struct persona{
	char name[20];
	int nacim[3]; // [dia][mes][año]
} persona;


int menu();
void crearPersona(persona[][5], int[]); //Agrega una persona al calendario
void verCumples(int, persona[][5], int[]); //Ve los cumples de determinado mes
void verCalendario(persona[][5], int[]); //Ve el calendario (todos los cumples)
void encontrarCumpleDia(int, persona[][5], int[], int, int); //Busca los cumple de un dia especifico