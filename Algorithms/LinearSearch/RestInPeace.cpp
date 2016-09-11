#include <stdio.h>


int check_number(int number){
	if ((number%21)==0){
		return 1;
	}

	bool last_digit=false;
	while(number>0){
		int ret = number%10;
		if (ret == 1){
			last_digit = true;
		}else if ((ret==2) && last_digit){
			return 1;
		}else{
			last_digit = false;
		}
		number = number/10;
	}
	return 0;
}

int main(){
	int lines;
	scanf("%d", &lines);

	for(int i=0;i<lines;i++){
		int number;
		scanf("%d", &number);
		if (check_number(number)){
			printf("The streak is broken!\n");
		}else{
			printf("The streak lives still in our heart!\n");
		}
	}
	return 0;
}