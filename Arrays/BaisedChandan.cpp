#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	int lines;
	scanf("%d", &lines);
	stack<int> s;
	int input;
	int total_rating=0;
	for(int i=0;i<lines;i++){
		scanf("%d", &input);
		if (input !=0){
			total_rating += input;
			s.push(input);
		}else{
			if (!s.empty()){
				input = s.top();
				s.pop();
				total_rating -= input;
			}
		}
	}
	printf("%d\n", total_rating);
	return 0;
}