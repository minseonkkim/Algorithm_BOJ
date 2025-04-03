#include <iostream>
using namespace std;

bool check[2500];

int main() {
	string str;
	cin >> str;
	string dock = "quack";
	int answer = 0;
	while(true){
		int idx = 0;
		bool find = false;
		for(int i = 0; i < str.length(); i++){
			if(!check[i] && str[i] == dock[idx]){
				find = true;
				check[i] = true;
				idx++;
				if(idx == 5) {
					idx = 0;
				}
			}
		}
		if(idx != 0 || !find) break;
		answer++;
	}
	bool wrong = false;
	for(int i = 0; i < str.length(); i++){
		if(!check[i]){
			wrong = true;
			break;
		}
	}
	if(wrong || str.length() % 5 != 0) cout << -1;
	else cout << answer;
	return 0;
}
