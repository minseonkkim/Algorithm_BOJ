#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> type;
int cnt[10];

int main() {
	cin >> n;
	type.push_back(0);
	for(int i = 0; i < n; i++){
		int tp;
		cin >> tp;
		type.push_back(tp);
	}
	
	int l = 1, r = 1, type_cnt = 1, answer = 0;
	cnt[type[1]]++;
	while(r <= n){
		if(type_cnt <= 2){
			answer = max(answer, r - l + 1);
			r++;
			if(cnt[type[r]]++ == 0) type_cnt++;
		} else {
			if(--cnt[type[l]] == 0) type_cnt--;
			l++;
		}
	}
	cout << answer;
	return 0;
}
