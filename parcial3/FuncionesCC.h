#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

//PARCIAL 2 Daniel Caicedo Jaramillo

#define MAX_NAME 35
#define MAX_EMAIL 45
#define MAX_PISOS 100
#define MAX_LOCALES 100
#define MAX_PERSONAS 50

//Uso de enums
enum estadoLocal {NODISPONIBLE = 0, DISPONIBLE = 1};
enum tipoPersona {EMPLEADO = 0, ARRENDATARIO = 1};

typedef struct Persona{
	char nombre[MAX_NAME];
	int id;
	int celular;
	char email[MAX_EMAIL];
	int tipo;
} Persona;
//Local 
typedef struct Local{
	char nombreLocal[MAX_NAME];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	int disponible; //1 true 0 false
	int precio;
	Persona personas[MAX_PERSONAS];
	int numPersonas;
} Local;

typedef struct CentroC{
	char nombreCentro[MAX_NAME];
	int pisos;
	int localesxPiso;
	Local locales[MAX_PISOS][MAX_LOCALES];
} CentroC;


/*Agregar las funciones que necesite para satisfacer los requerimientos */
void mostrarLocal(Local ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso);

CentroC * crearCentroComercial(int * fil, int * col, char * name);
void agregarLocal(int fil, int col, Local centroComercial[][MAX_LOCALES] );
void eliminarLocal(int fil, int col, Local centroComercial[][MAX_LOCALES]);
void verTodosLocales(int fil, int col, Local centroComercial[][MAX_LOCALES]);
int cantidadLocalesDisponibles(int fil, int col, Local centroComercial[][MAX_LOCALES], int i, int j, int counter);
void verLocalesDisponibles(int fil, int col, Local centroComercial[][MAX_LOCALES], int i, int j);
void modificarNombreLocal(int fil, int col, Local centroComercial[][MAX_LOCALES]);
void agregarPersonaLocal(int fil, int col, Local centroComercial[][MAX_LOCALES]);
int menu();

#endif /* FUNCIONESCC_H_ */
