#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	priority_queue<long long> pq;
	int n, k;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> k;
			pq.push(-k);
			if(pq.size() > n) pq.pop();
		}
	}

	cout << -pq.top() << endl;
	return 0;
}
