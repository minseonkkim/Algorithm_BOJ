#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, a, k;
	cin >> n;
	
	priority_queue<int> pq;
	
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a == 0){
			if(pq.empty()) {
				cout << -1 << endl;
			}
			else {
				int t = pq.top();
				pq.pop();
				cout << t << endl;
			}
			
		} else {
			for(int i = 0; i < a; i++){
				cin >> k;
				pq.push(k);
			}
		}
	}
	return 0;
}
