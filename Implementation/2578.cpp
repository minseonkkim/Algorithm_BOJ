#include <iostream>
#include <unordered_map>
using namespace std;

int board[5][5];
bool check[5][5];
unordered_map<int, pair<int, int>> um;

bool isBingo(){
	int cnt = 0;
	for(int i = 0; i < 5; i++){
		bool flag = true;
		for(int j = 0; j < 5; j++){
			if(check[i][j] == false) {
				flag = false;
				break;
			}
		}
		if(flag) cnt++;
	}
	for(int j = 0; j < 5; j++){
		bool flag = true;
		for(int i = 0; i < 5; i++){
			if(check[i][j] == false) {
				flag = false;
				break;
			}
		}
		if(flag) cnt++;
	}
	bool flag = true;
	for(int i = 0; i < 5; i++){
		if(check[i][i] == false){
			flag = false;
			break;
		}
	}
	if(flag) cnt++;
	
	flag = true;
	for(int i = 0; i < 5; i++){
		if(check[i][4 - i] == false){
			flag = false;
			break;
		}
	}
	if(flag) cnt++;
	
	if(cnt >= 3) return true;
	else return false;
}

int main() {
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> board[i][j];
			um[board[i][j]] = {i, j};
		}
	}
	for(int i = 1; i <= 25; i++){
		int num; 
		cin >> num;
		check[um[num].first][um[num].second] = true;
		if(isBingo()){
			cout << i;
			break;
		}
	}
	return 0;
}
