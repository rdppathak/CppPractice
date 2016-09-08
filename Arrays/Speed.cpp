#include <stdio.h>
#include <stdlib.h>

int main(){
	int lines;
	scanf("%d", &lines);
	for(int i=0;i<lines;i++){
		int cars;
		int min_speed = 0;
		int total=0;
		int curr_car;
		scanf("%d", &cars);
		for(int j=0;j<cars;j++){
			scanf("%d", &curr_car);
			if (min_speed == 0){
				total++;
				min_speed = curr_car;
			}else if(curr_car<=min_speed){
				total++;
				min_speed = curr_car;
			}
		}
		printf("%d\n", total);
	}
}