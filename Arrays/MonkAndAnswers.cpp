#include <stdio.h>
#include <stdlib.h>

int main(){
	int questions;
	int max_attempt;
	int skips=0;
	int max_solved=0;
	scanf ("%d", &questions);
	scanf("%d", &max_attempt);
	int curr_question;
	for(int i=0;i<questions;i++){
		scanf("%d", &curr_question);
		if (curr_question <= max_attempt && skips<=1){
			max_solved++;
		}else{
			if (skips>1){
				break;
			}
			skips++;
		}
	}
	printf("%d\n", max_solved);
	return 0;
}
