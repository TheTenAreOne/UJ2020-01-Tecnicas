#include "FuncionesCC.h"
#include <stdio.h>

//PARCIAL 2 Daniel Caicedo Jaramillo

int main(){
	
	int filCC, colCC, i, option; // CC = centro comercial
	Local ** centroC;
	
	//1. Solicitar el número de pisos y locales
	printf("==Crear centro comercial==\n");
	printf("Numero de pisos: "); scanf("%d", &filCC);
	printf("Numero de locales por piso: "); scanf("%d", &colCC);
	centroC = crearCentroComercial(&filCC, &colCC);
	printf("Centro comercial creado\n");

	// Los pisos empiezan en 0! Importante, empiezan en 0!

	do{
		option = menu();
		switch(option){
			case 1:
				//2. Agrega un local al centro comercial
				agregarLocal(filCC, colCC, centroC);
				break;
			case 2:
				//5. Elimina un local (lo vuelve disponible)
				eliminarLocal(filCC, colCC, centroC);
				break;
			case 3:
				//3. Consulta info (mi version de ver locales)
				verTodosLocales(filCC, colCC, centroC);
				break;
			case 4:
				//3. Consulta info (recursive)
				printf("# de locales disponibles: %d\n", 
				cantidadLocalesDisponibles(filCC, colCC, centroC, 0, 0, 0));
				break;
			case 5:
				//3. Consulta info (recursive)
				printf("==Locales disponibles==\n");
				verLocalesDisponibles(filCC, colCC, centroC, 0, 0);
				break;
			case 6:
				//4. Modificar info de local
				modificarNombreLocal(filCC, colCC, centroC);
				break;
		}
	}while(option != 0);
	
	return 0;
}

