#include "FuncionesCC.h"
#include <stdio.h>
#include <string.h>

//PARCIAL 2 Daniel Caicedo Jaramillo

enum cargarCentro {CARGARCENTRO = 1, CREARCENTRO = 2};

int main(){
	
	int filCC, colCC, i, option; // CC = centro comercial
	char fileName[MAX_NAME];
	char nombreCC[35];
	CentroC centroC;
	int loaded;
	
	do{
		printf("1. Cargar Centro comercial\n");
		printf("2. Crear Centro comercial\n");
		printf("==> "); scanf("%d", &option);
	}while( option != 1 && option != 2 );
	
	if( option == 1 ){
		do{
			printf("file name: "); scanf( "%s", fileName );
			loaded = loadCentro( &centroC, fileName );
			filCC = centroC.pisos;
			colCC = centroC.localesxPiso;
			if( loaded == 0 ){
				printf("File not found\n");
				printf("1 to try again  2 To create\n");
				printf("==>"); scanf("%d", &option );
				if( option == 2 ){
					goto CREATE;
				}
			}
		}while( loaded == 0 );
	}else{
		//1. Solicitar el número de pisos y locales
		CREATE:
		printf("==Crear centro comercial==\n");
		printf("Nombre del centro comercial: "); scanf("%s", nombreCC);
		printf("Numero de pisos: "); scanf("%d", &filCC);
		printf("Numero de locales por piso: "); scanf("%d", &colCC);
		printf("piso:%d  localesxPiso:%d\n", filCC, colCC); // -------------------------------------------
		centroC = crearCentroComercial(&filCC, &colCC, nombreCC);
		printf("Centro comercial creado\n");
		strcpy( fileName, nombreCC );
		strcat( fileName, ".dat" );
		printf("Archivo del centro comercial: %s\n", fileName);
	}
	
	

	// Los pisos empiezan en 0! Importante, empiezan en 0!

	do{
		option = menu();
		switch(option){
			case 1:
				//2. Agrega un local al centro comercial
				agregarLocal(filCC, colCC, centroC.locales, &centroC );
				break;
			case 2:
				//5. Elimina un local (lo vuelve disponible)
				eliminarLocal(filCC, colCC, centroC.locales, &centroC );
				break;
			case 3:
				//3. Consulta info (mi version de ver locales)
				verTodosLocales(filCC, colCC, centroC.locales);
				break;
			case 4:
				//3. Consulta info (recursive)
				printf("# de locales disponibles: %d\n", 
				cantidadLocalesDisponibles(filCC, colCC, centroC.locales, 0, 0, 0));
				break;
			case 5:
				//3. Consulta info (recursive)
				printf("==Locales disponibles==\n");
				verLocalesDisponibles(filCC, colCC, centroC.locales, 0, 0);
				break;
			case 6:
				//4. Modificar info de local
				modificarNombreLocal(filCC, colCC, centroC.locales);
				break;
			case 7:
				agregarPersonaLocal(filCC, colCC, centroC.locales);
				break;
			case 8:
				mostrarNombresLocalesOrden( &centroC , filCC, colCC );
				break;
			case 9:
				mostrarLocalesOrdenPrecio( &centroC, filCC, colCC );
				break;
		}
	}while(option != 0);
	
	saveCentro( &centroC, fileName );
	
	return 0;
}

