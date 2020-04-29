#include <stdio.h>
#include <time.h>

void swap(int * a, int * b){
	int temp;
	temp = *a; *a = *b; *b = temp;
}

void bubbleSort(int * array, int size){
	int i, k;
	int swapped;
	for(i = 0; i < size; i++){
		swapped = 0;
		for(k = 0; k < size - 1; k++){
			if(array[k] > array[k + 1]){
				swap( &array[i], &array[k + 1]);
				swapped = 1;
			}
		}
		if(!swapped){
			return;
		}
	}
	return;
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
	
	f = fopen( "sortInfoBubbleSort.txt", "a");
	fprintf(f, "---------------------------\n");
	fprintf(f, "   = Bubble sort Improved =     \n");
	fprintf(f, "# of elements: %d\n", size);
	fprintf(f, "Starting time: %d\n", start );
	
	bubbleSort(array, size);
	
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