#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

bool compare2(int a, int b){
	return a > b;
}

int main() {
	int n, t, s, time;
	vector<pair<int, int>> v;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t >> s;
		v.push_back({t, s});
	}
	
	sort(v.begin(), v.end(), compare);
	time = v[0].second - v[0].first;
	
	for(int i = 1; i < n; i++){
		if(time < v[i].second) time -= v[i].first;
		else {
			time = v[i].second;
			time -= v[i].first;
		}
	}

	if(time < 0) cout << -1 << endl;
	else cout << time << endl;
	
	return 0;
}
