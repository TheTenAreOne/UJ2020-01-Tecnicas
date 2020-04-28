#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//https://www.geeksforgeeks.org/merge-sort/
//https://www.youtube.com/watch?v=JSceec-wEyw
//Esta implementación de merge sort la he visto
//los links anteriores.

void merge(int * array, int left, int middle, int right){
	
	int i, j, k;
	int size1 = middle - left + 1;
	int size2 = right - middle;
	
	int Left[size1], Right[size2];
	
	for(i = 0; i < size1; i++){
		Left[i] = array[left + i];
	}
	for(i = 0; i < size2; i++){
		Right[i] = array[middle + 1 + i];
	}
	
	i = j = 0;
	k = left;
	while(i < size1 && j < size2){
		
		if(Left[i] <= Right[j]){
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

void mergeSort(int * array, int left, int right){
	
	if(left < right){
		
		int middle = left + (right - left)/2;
		
		mergeSort(array, left, middle);
		mergeSort(array, middle+1, right);
		
		merge(array, left, middle, right);
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
	
	printf("\nunsorted:\n");
	for(i = 0; i < size; i++){
		printf(" %d", array[i]);
	}
	
	start = clock();
	
	f = fopen( "sortInfo.txt", "a");
	fprintf(f, "---------------------------\n");
	fprintf(f, "       = Merge sort  =     \n");
	fprintf(f, "# of elements: %d\n", size);
	fprintf(f, "Starting time: %d\n", start );
	
	mergeSort(array, 0, size - 1);
	
	end = clock();
	
	fprintf(f, "Finish time: %d\n", end );
	fprintf(f, "Time used: %lf\n", (double)(end - start) );
	fprintf(f, "---------------------------\n");
	fclose( f );
	
	printf("\nsorted:\n");
	for(i = 0; i < size; i++){
		printf(" %d", array[i]);
	}
	
	return 0;
}