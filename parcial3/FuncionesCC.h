#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

//PARCIAL 2 Daniel Caicedo Jaramillo

#define MAX_NAME 35

//Uso de enums
enum estadoLocal {NODISPONIBLE = 0, DISPONIBLE = 1};



//Local 
typedef struct Local{
	char nombreLocal[MAX_NAME];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	int DISPONIBLE; //1 true 0 false
} Local;

typedef struct CentroC{
	char nombreCentro[MAX_NAME];
	int pisos;
	int localesxPiso;
	Local ** locales;
} CentroC;


/*Agregar las funciones que necesite para satisfacer los requerimientos */
void mostrarLocal(Local ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso);

CentroC * crearCentroComercial(int * fil, int * col, char * name);
void agregarLocal(int fil, int col, Local ** centroComercial);
void eliminarLocal(int fil, int col, Local ** centroComercial);
void verTodosLocales(int fil, int col, Local ** centroComercial);
int cantidadLocalesDisponibles(int fil, int col, Local ** centroComercial, int i, int j, int counter);
void verLocalesDisponibles(int fil, int col, Local ** centroComercial, int i, int j);
void modificarNombreLocal(int fil, int col, Local ** centroComercial);
int menu();

#endif /* FUNCIONESCC_H_ */
