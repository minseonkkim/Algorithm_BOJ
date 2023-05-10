#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		pq.push(x);
	}
	
	int answer = 0;
	while(pq.size() > 1){
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		answer += a + b;
		pq.push(a + b);
	}
	cout << answer << endl;
	
	return 0;
}
