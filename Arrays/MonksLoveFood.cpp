#include <stdio.h>
#include <stack>
using namespace std;

#define CUSTOMER 1
#define CHEF 2

int main(){
	int lines;
	scanf("%d", &lines);
	stack<int> s;
	int query, cost;
	for(int i=0;i<lines;i++){
		scanf("%d", &query);
		if (query == CUSTOMER){
			if (s.empty()){
				printf ("No Food\n");
			}else{
				cost = s.top();
				s.pop();
				printf("%d\n", cost);
			}
		}else if (query == CHEF){
			scanf("%d", &cost);
			s.push(cost);
		}
	}
	return 0;
}