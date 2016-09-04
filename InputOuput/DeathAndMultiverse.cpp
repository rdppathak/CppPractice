#include <stdio.h>

int main(){
	int lines;
	scanf("%d", &lines);
	int input;
	for(int i=0;i<lines;i++){
		scanf("%d", &input);
		printf("%d\n", input-1);
	}
	return 0;
}