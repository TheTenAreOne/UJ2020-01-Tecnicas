#include "FuncionesCC.h"
#include <stdlib.h>
#include <string.h>

//PARCIAL 2 Daniel Caicedo Jaramillo


//Crea el centro comercial de fil pisos y col cantidad de locales
Local ** crearCentroComercial(int * fil, int * col){
	// PASO POR REFERENCIA AQUI!
	int i, j, counter = 1;
	
	// USO DE MEMORIA DINAMICA AQUI!
	
	Local ** centroC = malloc(sizeof(Local*) * (*fil));
	
	for(i = 0; i < *col; i++){
		centroC[i] = malloc(sizeof(Local) * (*col));
	}
	
	for(i = 0; i < *fil; i++){
		for(j = 0; j < *col; j++){
			Local newLocal;
			newLocal.disponible = 1;
			newLocal.idLocal = counter;
			counter++;
			centroC[i][j] = newLocal;
		}
	}
	
	return centroC;
}


//Agrega un local en el piso deseado y la posición deseada
void agregarLocal(int fil, int col, Local ** centroComercial){
	int piso, local;
	do{
		printf("Piso: "); scanf("%d", &piso);
		if(piso > fil || piso < 0)
			printf("numero invalido max:%d\n", fil-1);
	}while(piso < 0 || piso >= fil);
		
	do{
		printf("Numero de local: "); scanf("%d", &local);
		if(centroComercial[piso][local].disponible == noDisponible)
			printf("Local no disponible\n");
	}while(local < 0 || local >= col || 
	centroComercial[piso][local].disponible == noDisponible);
	
	centroComercial[piso][local].pisoLocal = piso;
	centroComercial[piso][local].numLocalxPiso = local;
	centroComercial[piso][local].disponible = 0;
	printf("nombre: "); scanf("%s", centroComercial[piso][local].nombreLocal);
	printf("Local <%s> creado exitosamente\n", centroComercial[piso][local].nombreLocal);
	return;
}


//Elimina un local (si se encontraba no disponible, ahora estara disponible)
void eliminarLocal(int fil, int col, Local ** centroComercial){
	int piso, local;
	do{
		printf("Piso: "); scanf("%d", &piso);
		if(piso > fil || piso < 0)
			printf("numero invalido max:%d\n", fil-1);
	}while(piso < 0 || piso >= fil);
		
	do{
		printf("Numero de local: "); scanf("%d", &local);
		if(local > col || local < 0)
			printf("numero invalido max:%d\n", col-1);
	}while(local < 0 || local >= col);
	centroComercial[piso][local].disponible = disponible;
	printf("El local <ID:%d> ahora se encuentra disponible\n", 
	centroComercial[piso][local].idLocal);
	return;
}

//Ver todos los locales arrendados
void verTodosLocales(int fil, int col, Local ** centroComercial){
	int i, j;
	for(i = 0; i < fil; i++){
		for(j = 0; j < col; j++){
			if(centroComercial[i][j].disponible == noDisponible){
				printf("[%s, piso: %d, local: %d, id: %d]\n",
				centroComercial[i][j].nombreLocal, 
				centroComercial[i][j].pisoLocal, 
				centroComercial[i][j].numLocalxPiso,
				centroComercial[i][j].idLocal);
			}
		}
	}
	return;
}

//Retorna el número de locales disponibles
int cantidadLocalesDisponibles(int fil, int col, Local ** centroComercial, int i, int j, int counter){
	if(j == col){
		j = 0;
		i++;
	}
	if(i == fil){
		return counter;
	}
	if(centroComercial[i][j].disponible == disponible){
		counter++;
	}
	j++;
	cantidadLocalesDisponibles(fil, col, centroComercial, i, j, counter);
}

//Muestra info de los locales disponibles
void verLocalesDisponibles(int fil, int col, Local ** centroComercial, int i, int j){
	if(j == col){
		j = 0;
		i++;
	}
	if(i == fil){
		return;
	}
	if(centroComercial[i][j].disponible == disponible){
		printf("[ID:%d, piso:%d, local:%d]\n",
		centroComercial[i][j].idLocal, i, j);
	}
	j++;
	verLocalesDisponibles(fil, col, centroComercial, i, j);
}

//Modifica el nombre de un local que este arrendado
void modificarNombreLocal(int fil, int col, Local ** centroComercial){
	int piso, local;
	char oldName[35];
	do{
		printf("Piso: "); scanf("%d", &piso);
		if(piso > fil || piso < 0)
			printf("numero invalido max:%d\n", fil-1);
	}while(piso < 0 || piso >= fil);
		
	do{
		printf("Numero de local: "); scanf("%d", &local);
		if(local > col || local < 0)
			printf("numero invalido max:%d\n", col-1);
	}while(local < 0 || local >= col);
	
	if(centroComercial[piso][local].disponible == disponible){
		printf("Este local no ha sido arrendado\n");
		return;
	}
	strcpy(oldName, centroComercial[piso][local].nombreLocal);
	printf("Nuevo nombre: "); scanf("%s", centroComercial[piso][local].nombreLocal);
	printf("%s ahora se llama %s\n", oldName, centroComercial[piso][local].nombreLocal);
}


//Menu 
int menu(){
	int option;
	printf("=Centro Comercial=\n");
	printf("1. Agregar local\n");
	printf("2. Eliminar local\n");
	printf("3. Listar todos los locales\n");
	printf("4. # de locales disponibles\n");
	printf("5. Ver locales disponibles\n");
	printf("6. Cambiar nombre local\n");
	printf("0. Salir\n");
	printf("==> "); scanf("%d", &option);
	
	return option;
}


//PARCIAL 2 Daniel Caicedo Jaramillo

