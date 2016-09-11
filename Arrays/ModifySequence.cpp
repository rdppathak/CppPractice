#include <stdio.h>

int main(){
	int lines;
	scanf("%d", &lines);
	bool first=true;
	int prev=0;
	int curr;
	bool found = true;
	for(int i=0;i<lines;i++){
		scanf("%d", &curr);
		if(!first){
			if (prev!=curr){
				found = false;
				break;
			}else if (curr > lines){
				found = false;
			}
		}else{
			first=false;
		}
		prev = curr;
	}
	if (found || (lines == 1)){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}