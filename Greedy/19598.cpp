#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<>> pq;
	for(int i = 0; i < n; i++){
		int start, end;
		cin >> start >> end;
		v.push_back({start, end});
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++){
		if(pq.empty()) {
			pq.push(v[i].second);
			continue;
		}
		
		if(v[i].first >= pq.top()) pq.pop();
		pq.push(v[i].second);
	}
	cout << pq.size() << endl;
	return 0;
}
