#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char check_begin_set[] = {'[', '{', '(', '\0'};
// char check_begin_set[] = {'1', '2', '3', '\0'};
char check_end_set[] = {']', '}', ')', '\0'};
struct Node{
	char s;
	struct Node *next;
};

struct Node* NewNode(char s){
	Node *temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->s = s;
	temp->next = NULL;
}

class Stack{
	private:
		Node *head;
	public:
	Stack(){
		head =NULL;
	}

	~Stack(){
	}

	void Push(char s){
		if (head == NULL){
			Node *temp = NewNode(s);
			head = temp;
		}else{
			Node *temp = NewNode(s);
			temp->next = head;
			head = temp;
		}
	}

	char Pop(){
		if (head == NULL){
			printf ("Error: stack empty");
		}else{
			Node *temp = head;
			head = head->next;
			char ret = temp->s;
			free(temp);
			return ret;
		}
	}

	char Peep(){
		if (head == NULL){
			printf ("Error: stack empty");
		}else{
			return head->s;
		}	
	}
	void PrintStack(){
		Node *temp;
		temp = head;
		int count=0;
		while(temp!=NULL){
			printf("stack[%d]: %c\n", count, temp->s);
			temp=temp->next;
			count++;
		}
	}

	int isEmpty(){
		if (head == NULL){
			return 1;
		}
		return 0;
	}
};

int CheckBeginChar(char ch){
	for(int i=0;i<strlen(check_begin_set);i++){
		if (check_begin_set[i] == ch){
			return 1;
		}
	}
	return 0;
}

int CheckEndChar(char ch){
	for(int i=0;i<strlen(check_end_set);i++){
		if (check_end_set[i] == ch){
			return 1;
		}
	}
	return 0;
}

int main(){
	char str[100];
	Stack s;
	printf("Enter any piece of code\n");
	gets(str);

	int string_len = strlen(str);
	int current_char = 0;
	while(current_char<string_len){
		if (CheckBeginChar(str[current_char]) ==1){
			s.Push(str[current_char]);
		}else if(CheckEndChar(str[current_char]) == 1){
			if (s.isEmpty()){
				printf("Parenthesis/Bracket/Braces mismatch, please check\n");
				return 0;
			}
			char ch = s.Peep();
			if(ch == '[' and str[current_char] == ']'){
				char temp = s.Pop();
			}else if(ch == '{' and str[current_char] == '}'){
				char temp = s.Pop();
			}else if (ch == '(' and str[current_char] == ')'){
				char temp = s.Pop();
			}else{
				printf("Parenthesis/Bracket/Braces mismatch, please check\n");
				return 0;
			}
		}
		current_char++;
	}
	printf("Parenthesis/Bracket/braces matches properly\n");
	return 0;
}