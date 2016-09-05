#include <stdio.h>

int main(){
	int low, high;
	int divisor;
	int count=0;

	scanf("%d", &low);
	scanf("%d", &high);
	scanf("%d", &divisor);

	for(int i=low;i<=high;i++){
		if ((i%divisor) == 0){
			count++;
		}
	}
	printf("%d", count);
}