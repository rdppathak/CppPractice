#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char convert(unsigned char character){
	if (character >= 65 && character <=90){
		return (character+32);
	}else{
		return (character-32);
	}
}

char* toggle_string(char* input){
	int len = strlen(input);
	char* new_string = (char*)malloc(sizeof(char)*len);
	for(int i=0;i<len;i++){
		new_string[i] = convert(input[i]);
	}
	new_string[len] = '\0';
	return new_string;
}

int main(){
	char str[100];
	scanf("%s", str);
	printf("%s\n", toggle_string(str));
	return 0;
}