#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

deque<pair<int, int>> dq;

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		dq.push_back({i, x});
	}
	
	while(!dq.empty()){
		cout << dq.front().first << " ";
		int move = dq.front().second;
		dq.pop_front();
		
		if(dq.empty()) break;
		 
		if(move > 0){
			for(int i = 0; i < move - 1; i++){
				pair<int, int> tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
		} else{
			for(int i = 0; i < abs(move); i++){
				pair<int, int> tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
		}
	}
	return 0;
}
