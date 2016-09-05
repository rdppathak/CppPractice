#include <stdio.h>
#include <math.h>

#define MODULO (long int)pow(10, 9)

int main(){
	int numbers;
	long int input;
	long int product=1;

	scanf("%d", &numbers);

	for(int i=0;i<numbers;i++){
		scanf("%ld", &input);
		product = (product*input)%(MODULO+7);
	}
	printf("%ld", product);
	return 0;
}