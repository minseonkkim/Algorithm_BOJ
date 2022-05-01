#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> time(n);
	for(int i = 0; i < n; i++){
		cin >> time[i];
	}
	sort(time.begin(), time.end(), greater<>());
	
	if(m > n){   // 예외처리
		cout << time[0] << endl;
		return 0;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < m; i++){
		pq.push(time[i]);
	}
	for(int i = m; i < n; i++){
		int t = pq.top() + time[i];
		pq.pop();
		pq.push(t);
	}
	
	for(int i = 0; i < m - 1; i++) pq.pop();
	cout << pq.top() << endl;
	return 0;
}
