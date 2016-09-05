#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool is_nice_arches(string input){
	stack<char> s;
	if ((input.length()%2)!=0){
		return false;
	}

	for(int i=0;i<input.length();i++){
		if(s.size() == 0){
			s.push(input[i]);
		}else{
			if (s.top() == input[i]){
				s.pop();
			}else{
				s.push(input[i]);
			}
		}
	}
	if(s.size()==0){
		return true;
	}
	return false;
}

int main(){
	int lines;
	scanf("%d", &lines);
	int total = 0;
	for(int i=0;i<lines;i++){
		string input;
		cin >> input;
		if (is_nice_arches(input)){
			total++;
		}
	}
	cout <<total<<endl;
	return 0;
}