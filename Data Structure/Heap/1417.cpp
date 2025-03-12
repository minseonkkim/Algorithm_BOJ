#include <iostream>
#include <queue>
using namespace std;

int n, dasom;
priority_queue<int> pq;

int main(){
	cin >> n >> dasom;
	for(int i = 1; i < n; i++){
		int x;
		cin >> x;
		pq.push(x);
	}
	int cnt = 0;
	while(!pq.empty() && pq.top() >= dasom){
		int top = pq.top();
		pq.pop();
		pq.push(top - 1);
		dasom++;
		cnt++;
	}
	cout << cnt;
	return 0;
}
