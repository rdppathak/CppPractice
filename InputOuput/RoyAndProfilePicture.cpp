#include <stdio.h>


int main(){
	int boundary;
	scanf("%d", &boundary);
	int samples;
	scanf("%d", &samples);
	int h, w;
	for(int i=0;i<samples;i++){
		scanf("%d", &w);
		scanf("%d", &h);

		if ((h< boundary) || (w<boundary)){
			printf("UPLOAD ANOTHER\n");
		}else{
			if (w == h){
				printf("ACCEPTED\n");
			}else{
				printf("CROP IT\n");
			}
		}
	}
	return 0;
}