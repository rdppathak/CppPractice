#include <stdio.h>

int main(){
	int input;
	scanf("%d", &input);
	long int result = 1;
	while(input>1){
		result = result*input;
		input--;
	}
	printf("%ld\n", result);
	return 0;
}