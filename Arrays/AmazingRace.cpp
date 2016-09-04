#include <stdio.h>
#include <stdlib.h>

int lower_range_visible(int arr[], int size, int low, int high, int index){
	if (low > high)
		return 0;

	int value = 0;
	for(int i=high-1;i>=low;i--){
		if(arr[i] >= arr[index]){
			value++;
			break;
		}
		value++;
	}
	return value;
}

int higher_range_visible(int arr[], int size, int low, int high, int index){
	if (high >size){
		return 0;
	}
	int value = 0;
	for(int i=low;i<high;i++){
		if (arr[i] >= arr[index]){
			value++;
			break;
		}
		value++;
	}
	return value;
}

void check_range(int array[], int size){
	int index=1;
	int range=0;
	int total = 0;
	int first = true;
	for(int i=0;i<size;i++){
		range = lower_range_visible(array, size, 0, i, i) + higher_range_visible(array, size, i+1, size, i);
		if (range*(i+1)>total or first){
			index = i+1;
			total = range * index;
			first =false;
		}
	}
	printf ("%d\n", index);
}

int main(){
	int inputs;
	scanf("%d", &inputs);
	for(int i=0;i<inputs;i++){
		int drivers;
		scanf("%d", &drivers);
		int *array = (int*)malloc(sizeof(int)*drivers);
		for(int j=0;j<drivers;j++){
			scanf("%d", &array[j]);
		}
		check_range(array, drivers);
		free(array);
	}
	return 0;
}