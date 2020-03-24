#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//==== Daniel Caicedo Jaramillo & Maria Jose Suarez Peña

enum meses{
	ENERO = 1,
	FEBRERO = 2,
	MARZO = 3,
	ABRIL = 4,
	MAYO = 5,
	JUNIO = 6,
	JULIO = 7,
	AGOSTO = 8,
	SEPTIEMBRE = 9,
	OCTUBRE = 10,
	NOVIEMBRE = 11,
	DICIEMBRE = 12
};

typedef struct persona{
	char name[20];
	int nacim[3]; // [dia][mes][año]
} persona;

int menu(){
	int option;
	printf("1 Agregar persona\n");
	printf("2 Cumples del mes\n");
	printf("3 Ver todos los usuarios\n");
	printf("0 Salir\n");
	scanf("%d", &option);
	
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


int main(){
   
    int option, mes;
   
    persona calendario[12][5];
    int personasCount[12] = {};
	
    do{
		option = menu();
		
		switch(option){
			case 1:
			crearPersona(calendario, personasCount);
			break;
			case 2:
			printf("Mes: "); scanf("%d", &mes); 
			verCumples(mes, calendario, personasCount);
			break;
			case 3:
			verCalendario(calendario, personasCount);
			break;
			case 0:
			break;
		}
	}while(option != 0);

    return 0;
}