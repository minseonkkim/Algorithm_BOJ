#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
	return a.second > b.second;
}

int main() {
	int n, d, t;
	cin >> n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		cin >> d >> t;
		v.push_back({d, t});
	}
	sort(v.begin(), v.end(), compare);
	
	int day = v[0].second;
	for(int i = 0; i < n; i++){
		int tmp = 0;
		if(v[i].second < day) day = v[i].second;
		day -= v[i].first + tmp;
	}
	
	if(day < 0) cout << 0 << endl;
	else cout << day << endl;
	return 0;
}
