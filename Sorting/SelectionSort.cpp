#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int arr[], int size){
	int j;
	for (int i=1;i<size;i++){
		int key = arr[i];
		j = i-1;

		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void print_elements(int arr[], int size){
	for (int i=0;i<size;i++){
		printf ("%d ", arr[i]);
	}
	printf ("\n");
}

int main(){
	int arr[] = {10, 20, 3, 5, 1, 2, 6, 8, 9, 40 };

	int size = sizeof(arr)/sizeof(arr[0]);

	printf ("%d elements to be sorted using selection sort\n", size);

	SelectionSort(arr, size);

	printf ("Array Elements after Selection Sort: ");
	print_elements(arr, size);

	return 0;
}