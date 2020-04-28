#include <stdio.h>
#include <time.h>

void selectionSort(int * array, int size){
	int small, i, j, smallIndex, temp;
	
	for(i = 0; i < size; i++){
		small = array[i];
		smallIndex = i;
		for(j = i + 1; j < size; j++){
			if(small > array[j]){
				small = array[j];
				smallIndex = j;
			}
		}
		temp = array[i];
		array[i] = array[smallIndex];
		array[smallIndex] = temp;
	}
}

int main(){
	int i;
	
	int array[99999];
	int size;
	
	FILE * f = fopen( "ints.dat", "rb" );
	fread( &size, sizeof(int), 1, f );
	fread( array, sizeof( int ), size, f);
	fclose( f );
	
	clock_t start, end;
	
	printf("unsorted\n");
	for(i = 0; i < size; i++){
		printf(" %d", array[i]);
	}
	
	start = clock();
	
	f = fopen( "sortInfo.txt", "a");
	fprintf(f, "---------------------------\n");
	fprintf(f, "   = Selection sort  =     \n");
	fprintf(f, "# of elements: %d\n", size);
	fprintf(f, "Starting time: %d\n", start );
	
	selectionSort(array, size);
	
	end = clock();
	
	fprintf(f, "Finish time: %d\n", end );
	fprintf(f, "Time used: %lf\n", (double)(end - start) );
	fprintf(f, "---------------------------\n");
	fclose( f );
	
	printf("\nsorted\n");
	for(i = 0; i < size; i++){
		printf(" %d", array[i]);
	}
	
	
	return 0;
}