#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getHeight(int *arr, int size, int parent){
	int height = -1;
	for(int i=0; i<size;i++){
		if (arr[i] == parent){
			printf("Found Child Node of [%d]->[%d]\n", parent, i);
			int theight = 1 + getHeight(arr, size, i);
			if (height ==-1){
				height = theight;
			}else if (theight >height){
				height = theight;
			}
		}
	}
	if (height == -1){
		return 1;
	}else{
		return height;
	}

}
int main(){
	int arr[5] = {4, -1, 4, 1, 1};
	int array_size = (sizeof(arr)/sizeof(*arr));
	printf("Number of elements in array: %d\n", array_size);
	int height = 0;
	for (int i=0;i<array_size; i++){
		if (arr[i] == -1){
			printf("Root Node found [%d]\n", i);
			height = getHeight(arr, array_size, i);
		}
	}
	printf("Maximum height of tree is: %d\n", height);
	return 0;
}