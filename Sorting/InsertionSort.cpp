#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort(int arr[], int size){
	for (int i=0;i<size-1;i++){
		int min_element = i;

		for(int j=i+1;j<size;j++){
			if (arr[j] <arr[min_element]){
				min_element = j;
			}
		}
		swap(&arr[min_element], &arr[i]);
	}
}

void print_elements(int arr[], int size){
	for (int i=0;i<size;i++){
		printf ("%d ", arr[i]);
	}
	printf ("\n");
}

int main(){
	printf ("Initializing insertion sort: \n");

	int arr [] = {9, 10, 20, 2, 5, 7, 3};
	int size = sizeof(arr)/sizeof(arr[0]);

	printf ("%d elements to be sorted\n", size);

	InsertionSort(arr, size);

	printf ("Sorted elements are as follows: ");
	print_elements(arr, size);
	return 0;
}