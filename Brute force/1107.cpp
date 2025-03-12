#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
vector<int> wrong;

bool canPress(int num){
	string snum = to_string(num);
	for(int i = 0; i < snum.length(); i++){
		if(find(wrong.begin(), wrong.end(), snum[i] - '0') != wrong.end()) return false;
	}
	return true;
}

int main() {
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		wrong.push_back(x);
	}
	
	int answer = abs(n - 100);
	for(int i = 0; i <= 1000000; i++){
		if(canPress(i)){
			int cnt = to_string(i).length() + abs(i - n);
			answer = min(answer, cnt);
		}
	}
	cout << answer;
	return 0;
}
