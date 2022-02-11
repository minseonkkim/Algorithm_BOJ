#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
	if(a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n, a, b, t, cnt = 1;
	cin >> n;
	
	vector<pair<int, int>> v;
	
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end(), compare);
	
	t = v[0].second;
	for(int i = 1; i < n; i++){
		if(v[i].first < t) continue;
		t = v[i].second;
		cnt++;
	}
	
	cout << cnt << endl;
	return 0;
}
