#include <stdio.h>
#include <string.h>

void check_occurrences(char str[], int length){
	int suvo_count=0;
	int suvojit_count=0;
	unsigned char last_occ=0;
	int match_len=0;

	for(int i=0;i<length;i++){
		if (match_len==0 && str[i]=='S'){
			match_len++;
		}else if(match_len==1 && str[i]=='U'){
			match_len++;
		}else if(match_len==2 && str[i]=='V'){
			match_len++;
		}else if(match_len==3 && str[i]=='O'){
			match_len++;
			suvo_count++;
		}else if(match_len==4 && str[i]=='J'){
			match_len++;
		}else if(match_len==5 && str[i]=='I'){
			match_len++;
		}else if(match_len==6 && str[i]=='T'){
			match_len=0;
			suvojit_count++;
			suvo_count--;
		}else{
			match_len=0;
			if (str[i] == 'S'){
				match_len++;
			}
		}
	}
	printf("SUVO = %d, SUVOJIT = %d\n", suvo_count, suvojit_count);
}

int main(){
	int lines;
	scanf("%d", &lines);
	for (int i=0;i<lines;i++){
		char str[150];
		scanf("%s", str);
		check_occurrences(str, strlen(str));
	}
	return 0;
}