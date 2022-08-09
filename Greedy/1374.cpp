#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n;
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<>> pq;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({b, c});
	}
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++){
		if(pq.empty()) {
			pq.push(v[i].second);
			continue;
		}
		if(pq.top() <= v[i].first) {
			pq.pop();
		}
		pq.push(v[i].second);
	}
	
	cout << pq.size() << endl;
	return 0;
}
