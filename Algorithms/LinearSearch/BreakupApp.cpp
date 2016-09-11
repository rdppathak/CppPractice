#include <stdio.h>
#include <list>
#include <string.h>
#include <stdlib.h>
using namespace std;

void check_breakup(char input[], int days[]){
	bool temp = false;
	int day=0;
	if (input[0] == 'G'){
		temp=true;
	}else{
		temp=false;
	}
	for(int i=0;i<strlen(input);i++){
		if (input[i] >=48 && input[i] <= 57){
			if (day!=0){
				day = day*10 + int(input[i]-'0');
			}else{
				day = day + int(input[i]-'0');
			}
			
		}else{
			if (day!=0){
				if (temp){
					days[day-1] += 2;
				}else{
					days[day-1] += 1;
				}
			}
			day=0;
		}
	}
	if (day!=0){
		if (temp){
			days[day-1] += 2;
		}else{
			days[day-1] += 1;
		}
	}
}

int main(){
	int lines;
	int selected_day=0;
	int matching = 0;
	int max_count=0;
	int days[30];
	int same_weight = 0;
	for (int i=0;i<30;i++){
		days[i] = 0;
	}

	scanf("%d", &lines);
	for (int i=0;i<lines;i++){
		char input[1000];
		scanf(" %[^\n]s", input);
		check_breakup(input, days);
	}
	for (int i=0;i<30-1;i++){
		int found=0;
		for(int j=i+1;j<30;j++){
			if (days[i] == days[j]){
				days[j] = 0;
				found =1;
			}
		}
		if (found){
			days[i]=0;
		}
	}

	for(int i=0;i<30;i++){
		if (days[i] >max_count){
			selected_day = (i+1);
		}
	}
	if (selected_day){
		printf("Date\n");
	}else{
		printf("No Date\n");
	}
	return 0;
}