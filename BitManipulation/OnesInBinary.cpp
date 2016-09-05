#include <stdio.h>

int main(){
	int lines;
	scanf("%d", &lines);
	for(int i=0;i<lines;i++){
		int input;
		int count=0;
		scanf("%d", &input);
		while(input >0){
			count++;
			input = (input)&(input-1);
		}
		printf("%d\n", count);
	}
	return 0;
}