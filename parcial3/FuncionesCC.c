#include "FuncionesCC.h"
#include <stdlib.h>
#include <string.h>

//PARCIAL 2 Daniel Caicedo Jaramillo


//Crea el centro comercial de fil pisos y col cantidad de locales
CentroC crearCentroComercial(int * fil, int * col, char * name){
	
	// PASO POR REFERENCIA AQUI!
	int i, j, counter = 1;
	
	// USO DE MEMORIA DINAMICA AQUI!

	
	CentroC centroC;
	
	strcpy( centroC.nombreCentro , name );
	
	centroC.pisos = *fil;
	
	centroC.localesxPiso = *col;
	
	for(i = 0; i < *fil; i++){
		for(j = 0; j < *col; j++){
			Local newLocal;
			newLocal.disponible = DISPONIBLE;
			newLocal.idLocal = counter;
			newLocal.precio = 0;
			newLocal.numPersonas = 0;
			counter++;
			centroC.locales[i][j] = newLocal;
			centroC.localesArrendados = 0;
			centroC.numDomicilios = 0;
		}
	}
	
	return centroC;
}


//Agrega un local en el piso deseado y la posición deseada
void agregarLocal(int fil, int col, Local centroComercial[][MAX_LOCALES], CentroC * centro ){
	int piso, local, precio;
	do{
		printf("Piso: "); scanf("%d", &piso);
		if(piso > fil || piso < 0)
			printf("numero invalido max:%d\n", fil-1);
	}while(piso < 0 || piso >= fil);
		
	do{
		printf("Numero de local: "); scanf("%d", &local);
		if(centroComercial[piso][local].disponible == NODISPONIBLE)
			printf("Local no disponible\n");
	}while(local < 0 || local >= col || 
	centroComercial[piso][local].disponible == NODISPONIBLE);
	
	centroComercial[piso][local].pisoLocal = piso;
	centroComercial[piso][local].numLocalxPiso = local;
	centroComercial[piso][local].disponible = 0;
	printf("nombre: "); scanf("%s", centroComercial[piso][local].nombreLocal);
	printf("precio: "); scanf("%d", &precio);
	centroComercial[piso][local].precio = precio;
	centro->localesArrendados++;
	printf("Local <%s> creado exitosamente\n", centroComercial[piso][local].nombreLocal);
	return;
}


//Elimina un local (si se encontraba no DISPONIBLE, ahora estara DISPONIBLE)
void eliminarLocal(int fil, int col, Local centroComercial[][MAX_LOCALES], CentroC * centro ){
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
	centroComercial[piso][local].disponible = DISPONIBLE;
	printf("El local <ID:%d> ahora se encuentra DISPONIBLE\n", 
	centroComercial[piso][local].idLocal);
	centro->localesArrendados--;
	return;
}

//Ver todos los locales arrendados
void verTodosLocales(int fil, int col, Local centroComercial[][MAX_LOCALES] ){
	int i, j;
	for(i = 0; i < fil; i++){
		for(j = 0; j < col; j++){
			if(centroComercial[i][j].disponible == NODISPONIBLE){
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

//Retorna el número de locales DISPONIBLEs
int cantidadLocalesDisponibles(int fil, int col, Local centroComercial[][MAX_LOCALES], int i, int j, int counter){
	if(j == col){
		j = 0;
		i++;
	}
	if(i == fil){
		return counter;
	}
	if(centroComercial[i][j].disponible == DISPONIBLE){
		counter++;
	}
	j++;
	cantidadLocalesDisponibles(fil, col, centroComercial, i, j, counter);
}

//Muestra info de los locales DISPONIBLEs
void verLocalesDisponibles(int fil, int col, Local centroComercial[][MAX_LOCALES], int i, int j){
	if(j == col){
		j = 0;
		i++;
	}
	if(i == fil){
		return;
	}
	if(centroComercial[i][j].disponible == DISPONIBLE){
		printf("[ID:%d, piso:%d, local:%d]\n",
		centroComercial[i][j].idLocal, i, j);
	}
	j++;
	verLocalesDisponibles(fil, col, centroComercial, i, j);
}

//Modifica el nombre de un local que este arrendado
void modificarNombreLocal(int fil, int col, Local centroComercial[][MAX_LOCALES]){
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
	
	if(centroComercial[piso][local].disponible == DISPONIBLE){
		printf("Este local no ha sido arrendado\n");
		return;
	}
	strcpy(oldName, centroComercial[piso][local].nombreLocal);
	printf("Nuevo nombre: "); scanf("%s", centroComercial[piso][local].nombreLocal);
	printf("%s ahora se llama %s\n", oldName, centroComercial[piso][local].nombreLocal);
}

//Agrega una persona a un local
void agregarPersonaLocal(int fil, int col, Local centroComercial[][MAX_LOCALES]){
	int piso, local, option, numPersonas, id, celular;
	Persona newPersona;
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
	
	if(centroComercial[piso][local].disponible == DISPONIBLE){
		printf("Este local no ha sido arrendado\n");
		return;
	}
	
	//METER AQUI EXCEPTION
	
	centroComercial[piso][local].numPersonas++;
	numPersonas = centroComercial[piso][local].numPersonas;
	
	printf("Nombre: "); scanf("%s", centroComercial[piso][local].personas[ numPersonas - 1].nombre );
	printf("Id: "); scanf("%d", &id );
	centroComercial[piso][local].personas[ numPersonas - 1].id = id;
	printf("# Celular: "); scanf("%d", &celular );
	centroComercial[piso][local].personas[ numPersonas - 1].celular = celular;
	printf("Email: "); scanf("%s", centroComercial[piso][local].personas[ numPersonas - 1].email );
	printf("Tipo: ");
	do{
		printf("(1)Empleado / (2)Arrendatario "); 
		scanf( "%d", &option );
		if( option == 1 ){
			centroComercial[piso][local].personas[ numPersonas - 1 ].tipo = EMPLEADO;
		}else if( option == 2 ){
			centroComercial[piso][local].personas[ numPersonas - 1 ].tipo = ARRENDATARIO;
		}else{
			printf("Elegir opcion valida porfavor.\n");
		}
	}while( option != 1 && option != 2 );
	
	printf("Se agrego a [%s] exitosamente\n", centroComercial[piso][local].personas[ numPersonas - 1].nombre );
}

int loadCentro( CentroC * centro, char * fileName ){
	FILE * fp = fopen( fileName, "rb" );
	if( fp == NULL ){
		return 0;
	}
	fread( centro, sizeof(*centro), 1, fp );
	fclose( fp );
	return 1;
}


void saveCentro( CentroC * centro, char * fileName ){
	FILE * fp = fopen( fileName, "wb" );
	fwrite( centro, sizeof(*centro), 1, fp );
	fclose( fp );
	return;
}


//Algoritmos de sorteo -------- Algoritmos de sorteo 


//Selection sort
void mostrarNombresLocalesOrden( CentroC  * centro , int fil, int col ){
	int i, j, min = 0, localNum, arrPos = 0;
	char arrNombres[ centro->localesArrendados ][MAX_NAME];
	localNum = centro->localesArrendados;
	char tempNombre[MAX_NAME];
	
	if( localNum == 0 ){
		printf("No hay locales\n");
		return;
	}
	
	for(i = 0; i < fil; i++ ){
		for(j = 0; j < col; j++ ){
			if(centro->locales[i][j].disponible == NODISPONIBLE ){
				strcpy( arrNombres[arrPos], centro->locales[i][j].nombreLocal );
				arrPos++;
			}
		}
	}
	
	//Selection sort ---------- Selection sort ---------- Selection sort
	arrPos = 0;
	for( i = 0; i < localNum - 1; i++ ){
		min = i;
		for( j = i + 1; j < localNum; j++ ){
			if( strcmp( arrNombres[j], arrNombres[min]) < 0 ){
				min = j;
			}
		}
		strcpy(tempNombre, arrNombres[min]);
		strcpy(arrNombres[min], arrNombres[i]);
		strcpy(arrNombres[i], tempNombre);
	}
	
	
	printf("=Locales ordenados alfabeticamente=\n");
	for( i = 0; i < localNum; i++ ){
		printf( " >Local: %s\n", arrNombres[i] );
	}
	
	return;
}


//Merge sort
void merge(Local * array, int left, int middle, int right){
	
	int i, j, k;
	int size1 = middle - left + 1;
	int size2 = right - middle;
	
	Local Left[size1], Right[size2];
	
	for(i = 0; i < size1; i++){
		Left[i] = array[left + i];
	}
	for(i = 0; i < size2; i++){
		Right[i] = array[middle + 1 + i];
	}
	
	i = j = 0;
	k = left;
	while(i < size1 && j < size2){
		
		if(Left[i].precio <= Right[j].precio){
			array[k] = Left[i];
			i++;
		}else{
			array[k] = Right[j];
			j++;
		}
		k++;
	}
	
	while(i < size1){
		array[k] = Left[i];
		i++;
		k++;
	}
	
	while(j < size2){
		array[k] = Right[j];
		j++;
		k++;
	}
	
	return;
}

void mergeSort( Local * array, int left, int right){
	
	if(left < right){
		
		int middle = left + (right - left)/2;
		
		mergeSort(array, left, middle);
		mergeSort(array, middle+1, right);
		
		merge(array, left, middle, right);
	}
	
	return;
}

void mostrarLocalesOrdenPrecio( CentroC * centro, int fil, int col ){
	
	int i, j, localesPos = 0;
	int numLocales = centro->localesArrendados;
	
	Local locales[numLocales];
	
	for( i = 0; i < fil; i++ ){
		for( j = 0; j < col; j++ ){
			if( centro->locales[i][j].disponible == NODISPONIBLE){
				locales[localesPos] = centro->locales[i][j];
				localesPos++;
			}
		}
	}
	
	mergeSort( locales, 0, numLocales - 1 );
	
	for( i = 0; i < numLocales; i++ ){
		printf("Local: %s <$ %d>\n", locales[i].nombreLocal, locales[i].precio);
	}
	
	return;
}

//Insertion sort

void mostrarPersonasOrdenNombre( CentroC * centro ){
	
	int piso, local;
	
	printf("Piso: "); scanf("%d", &piso);
	printf("Local: "); scanf("%d", &local);
	
	if( centro->locales[piso][local].disponible == DISPONIBLE ){
		printf("Este local no ha sido arrendado\n");
		return;
	}
	
	int numPersonas = centro->locales[piso][local].numPersonas;
	
	if( numPersonas == 0 ){
		printf("Este local no tiene personas\n");
		return;
	}
	
	Persona personas[numPersonas];
	
	int i,j;
	
	for( i = 0; i < numPersonas; i++ ){
		personas[i] = centro->locales[piso][local].personas[i];
	}
	
	
	char nombre[MAX_NAME];
	for( i = 1; i < numPersonas; i++ ){
		strcpy( nombre, personas[i].nombre);
		j = i - 1;
		
		while( j >= 0 && strcmp( nombre, personas[j].nombre) < 0 ){
			strcpy( personas[j + 1].nombre, personas[j].nombre);
			j = j - 1;
		}
		strcpy( personas[j + 1].nombre, nombre);
	}
	
	printf("Personas:\n");
	for( i = 0; i < numPersonas; i++ ){
		printf("> [%s, %d]\n", personas[i].nombre, personas[i].id );
	}
	
	return;
}


//Quicksort https://www.geeksforgeeks.org/quick-sort/

int partition (Persona * personas, int low, int high){ 
	
	Persona temp;
    int pivot = personas[high].id;   
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (personas[j].id < pivot) 
        { 
            i++;    
			temp = personas[i];
			personas[i] = personas[j];
			personas[j] = temp;
        } 
    }
	temp = personas[i + 1];
	personas[i + 1] = personas[high];
	personas[high] = temp;
    return (i + 1); 
} 

void quickSort(Persona * personas, int low, int high){ 
    if (low < high) 
    { 
        
        int pi = partition(personas, low, high); 
  
        quickSort(personas, low, pi - 1); 
        quickSort(personas, pi + 1, high); 
    } 
}


void mostrarPersonasOrdenID( CentroC * centro ){
	
	int i;
	
	int piso, local;
	
	printf("Piso: "); scanf("%d", &piso);
	printf("Local: "); scanf("%d", &local);
	
	if( centro->locales[piso][local].disponible == DISPONIBLE ){
		printf("Este local no ha sido arrendado\n");
		return;
	}
	
	int numPersonas = centro->locales[piso][local].numPersonas;
	
	if( numPersonas == 0 ){
		printf("Este local no tiene personas\n");
		return;
	}
	
	Persona personas[numPersonas];
	
	for( i = 0; i < numPersonas; i++ ){
		personas[i] = centro->locales[piso][local].personas[i];
	}
	
	printf("np: %d\n", numPersonas);
	
	quickSort( personas, 0, numPersonas - 1 );
	
	
	printf("Personas:\n");
	for( i = 0; i < numPersonas; i++ ){
		printf("> [%s, %d]\n", personas[i].nombre, personas[i].id );
	}
	
}



//Queue

void agregarDomicilio( CentroC * centro ){
	
	int celular;
	
	if( centro->numDomicilios == MAX_DOMICILIOS ){
		printf("Numero maximo de domicilios alcanzado!\n");
		return;
	}
	int numDomicilios = centro->numDomicilios;
	
	
	fflush( stdin );
	printf("Direccion: ");scanf("%[^\n]%*c", centro->domicilios[numDomicilios].direccion);
	
	fflush( stdin );
	printf("Celular: "); scanf("%d", &celular);
	centro->domicilios[numDomicilios].celular = celular;
	
	fflush( stdin );
	printf("Descripcion: "); scanf("%[^\n]%*c", centro->domicilios[numDomicilios].descripcion);
	centro->numDomicilios++;
	printf("Domicilio agregado\n");
	return;
}

void despacharDomicilio( CentroC * centro ){
	if( centro->numDomicilios == 0 ){
		printf("No hay domicilios pendientes\n");
		return;
	}
	int i;
	for( i = 0; i < centro->numDomicilios - 1; i++ ){
		centro->domicilios[ i ] = centro->domicilios[ i + 1 ];
	}
	centro->numDomicilios--;
	printf("Domicilio despachado\n");
	return;
}

void mostrarDomicilios( CentroC * centro ){
	if( centro->numDomicilios == 0 ){
		printf("No hay domicilios para mostrar\n");
		return;
	}
	int i;
	for( i = 0; i < centro->numDomicilios; i++ ){
		printf("------------------\n");
		printf("Direcion: %s\n", centro->domicilios[ i ].direccion);
		printf("Celular: %d\n", centro->domicilios[ i ].celular);
		printf("Descripcion: %s\n", centro->domicilios[ i ].descripcion);
		printf("------------------\n");
	}
	return;
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
	printf("7. Agregar persona a local\n");
	printf("8. Mostrar locales orden abc\n");
	printf("9. Mostrar orden por precio\n");
	printf("10. Mostrar personas local orden\n");
	printf("11. Mostrar personas orden id\n");
	printf("12. Agregar domicilio\n");
	printf("13. Despachar domicilio\n");
	printf("14. Mostrar domicilios\n");
	printf("0. Salir\n");
	printf("==> "); scanf("%d", &option);
	
	return option;
}


//PARCIAL 2 Daniel Caicedo Jaramillo

