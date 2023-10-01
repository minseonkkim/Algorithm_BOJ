#include <iostream>
#include <deque>
using namespace std;

int n, k;
deque<pair<int, bool>> dq;
int answer;

int main() {
	cin >> n >> k;
	for(int i = 0; i < 2 * n; i++){
		int x;
		cin >> x;
		dq.push_back({x, false});
	}
	while(true){
		answer++;
		// 1
		int t1 = dq.back().first;
		bool t2 = dq.back().second;
		dq.pop_back();
		dq.push_front({t1, t2});
		dq[n - 1].second = false;
		// 2
		for(int i = n - 2; i >= 0; i--){
			if(dq[i].second){
				if(!dq[i + 1].second && dq[i + 1].first > 0){
					dq[i].second = false;
					if(i != n - 2) dq[i + 1].second = true;
					dq[i + 1].first--;
				}
			}
		}
		// 3
		if(dq[0].first > 0) {
			dq[0].second = true;
			dq[0].first--;
		}
		// 4
		int cnt = 0;
		for(int i = 0; i < 2 * n; i++){
			if(dq[i].first <= 0) cnt++;
		}
		if(cnt >= k) break;
	}
	cout << answer;
	return 0;
}
