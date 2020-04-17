#include <stdio.h>

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
	int array[] = {19,4,5,1,2,6,9,10};
	int size = sizeof(array)/sizeof(array[0]);
	
	printf("unsorted\n");
	for(i = 0; i < size; i++){
		printf(" %d", array[i]);
	}
	selectionSort(array, size);
	printf("\nsorted\n");
	for(i = 0; i < size; i++){
		printf(" %d", array[i]);
	}
	
	return 0;
}