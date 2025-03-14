#include <iostream>
#include <queue>
using namespace std;

int n, m;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		long long x;
		cin >> x;
		pq.push(x);
	}
	
	for(int i = 0; i < m; i++){
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}
	
	long long answer = 0;
	while(!pq.empty()){
		answer += pq.top();
		pq.pop();
	}
	cout << answer;
	return 0;
}
