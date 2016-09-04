#include <string.h>
#include <stdio.h>
#include <stack>
using namespace std;
int main(){
	char str[101];
	scanf("%s", str);
	bool palindrome = true;
	stack <char>s;
	int len = strlen(str);
	for(int i=0;i<len;i++){
		if (((len%2)!=0) && (i == (len/2))){
			continue;
		}
		if (i<(len/2)){
			s.push(str[i]);
		}else{
			if (str[i] == s.top()){
				s.pop();
			}else{
				palindrome = false;
				break;
			}
		}
	}

	if (palindrome){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}