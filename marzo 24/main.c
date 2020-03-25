#include <stdio.h>
#include <string.h>
#include "calendario.h"

//==== Daniel Caicedo Jaramillo & Maria Jose Suarez Peña

int main(){
   
    int option, mes, dia;
   
    persona calendario[12][5]; //El calendario [12] = los meses, [5] = la capacidad por mes
    int personasCount[12] = {}; //Contador de personas por mes.
	
    do{
		option = menu();
		
		switch(option){
			case 1:
			printf("=======1=======\n");
			crearPersona(calendario, personasCount);
			printf("===============\n");
			break;
			case 2:
			printf("=======2=======\n");
			printf("Mes: "); scanf("%d", &mes); 
			verCumples(mes, calendario, personasCount);
			printf("===============\n");
			break;
			case 3:
			printf("======3========\n");
			verCalendario(calendario, personasCount);
			printf("===============\n");
			break;
			case 4:
			printf("======4========\n");
			printf("Dia: "); scanf("%d", &dia);
			encontrarCumpleDia(dia, calendario, personasCount, 0, 0);
			printf("===============\n");
			break;
			case 0:
			break;
		}
	}while(option != 0);

    return 0;
}