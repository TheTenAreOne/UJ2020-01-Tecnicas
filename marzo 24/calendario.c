#include "calendario.h"

int menu(){
	
	int option;
	printf("===Calendario Cumples===\n");
	printf("1 Agregar persona\n"); 
	printf("2 Cumples del mes\n"); 
	printf("3 Ver todos los usuarios\n"); 
	printf("4 Ver cumples de un dia\n"); 
	printf("0 Salir\n");
	printf("==> "); scanf("%d", &option);
	
	return option;
}

void crearPersona(persona calendario[12][5], int personasCount[12]){
	
	int mes;
	
	persona newP;
	
	printf("Nombre: "); scanf("%s", newP.name);
	printf("=Fecha de nacimiento=\n");
	fflush( stdin );
	printf("Dia: "); scanf("%d", &newP.nacim[0]);
	printf("Mes: "); scanf("%d", &newP.nacim[1]);
	printf("Anio: "); scanf("%d", &newP.nacim[2]);
	
	if(newP.nacim[1] == NOVIEMBRE)
		printf("<Sugoi>\n");
	if(newP.nacim[1] == DICIEMBRE && newP.nacim[0] == 24)
		printf("<MerryNawidad>\n");
	
	mes = newP.nacim[1]-1;
	
	if(personasCount[mes] >= 5){
		printf("Este mes esta lleno\n");
		return;
	}else{
		calendario[mes][personasCount[mes]++] = newP; 
		printf("{%s : %d/%d/%d}\n", newP.name, newP.nacim[0],newP.nacim[1],newP.nacim[2]);
	}
	
	return;
}

void verCumples(int mes, persona calendario[12][5], int personasCount[12]){
	
	int i;
	mes--;
	
	printf("\n===Cumples===\n\n");
	for(i = 0; i < personasCount[mes]; i++){
		printf("%s %d %d\n", calendario[mes][i].name, calendario[mes][i].nacim[0], calendario[mes][i].nacim[2]);
	}
	printf("\n===Final===\n\n");
	
	return;
}

void verCalendario(persona calendario[12][5], int personasCount[12]){
	
	int i, j, dia, mes;
	printf("Ingresa el dia actual: "); scanf("%d", &dia);
	printf("Ingrese el mes actual: "); scanf("%d", &mes);
	
	printf("===Calendario===\n");
	for(i = 0; i < 12; i++){
		for(j = 0; j < personasCount[i]; j++){
			if(calendario[i][j].nacim[0] == dia && calendario[i][j].nacim[1] == mes){
				printf("*");
			}
			printf("%s %d %d\n", calendario[i][j].name, calendario[i][j].nacim[0], calendario[i][j].nacim[2]);
		}
	}
	
	
	
	
	return;
}

void encontrarCumpleDia(int dia, persona calendario[12][5], int personasCount[12], int fil, int col){
	
	if(calendario[fil][col].nacim[0] == dia){
		printf(">>> %s cumple el %d del %d\n", calendario[fil][col].name, dia, calendario[fil][col].nacim[1]);
		return;
	}
	
	if(col == personasCount[fil]){
		fil++;
		col = 0;
	}else col++;
	
	if(fil == 12){ //Si llega a 12 ya se sale del calendario.
		printf("No se pudo encontrar\n");
		return;
	}
	encontrarCumpleDia(dia, calendario, personasCount, fil, col);
	
	return;
}