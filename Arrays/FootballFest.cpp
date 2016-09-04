#include <iostream>
using namespace std;

int main(){
	int test_cases;
	int curr_testcase = 0;
	cin >> test_cases;
	while(curr_testcase <test_cases){
		int total_passes;
		int init_player;
		int prev_player=-1;
		int curr_player;
		char action;
		cin >> total_passes;
		cin >>init_player;
		int passes=0;
		while(total_passes >passes){
			cin >>action;

			if (action == 'P'){
				prev_player = curr_player;
				cin >> curr_player;
			}else if (action == 'B'){
				int temp;
				temp = curr_player;
				curr_player = prev_player;
				prev_player = temp;
			}
			passes++;
		}
		cout << "Player "<<curr_player<<endl;
		curr_testcase++;
	}	

	return 0;
}