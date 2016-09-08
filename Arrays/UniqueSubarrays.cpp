#include <stdio.h>
#include <stdlib.h>
#include <map>

int check_unique_subarrays(int array[], int size){
	int subarray_size=0;
	for(int i=0;i<size;i++){
		map<int, int> sub_map;
		bool unique = true;
		if (sub_map.find(array[i]))
	}
}

int main(){
	int lines;
	scanf("%d", &lines);
	for (int i=0;i<lines;i++){
		int size;
		scanf("%d", &size);
		int *array;
		array = (int*)malloc(sizeof(int)*size);
		for(int j=0;j<size;j++){
			scanf("%d", &array[i]);
		}
	}
	return 0;
}