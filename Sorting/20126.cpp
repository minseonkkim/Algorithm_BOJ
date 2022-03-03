#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, s, x, y;
	vector<pair<int, int>> v;
	
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		v.push_back({x, y});
	}
	
	sort(v.begin(), v.end());
	
	if(v[0].first >= m){
		cout << 0 << endl;
		return 0;
	}
	
	int tmp = 0;
	for(int i = 0; i < n; i++){
		if(v[i].first - tmp >= m) {
			cout << tmp << endl;
			return 0;
		}
		tmp = v[i].first + v[i].second;
	}
	if(s - tmp >= m) cout << tmp << endl;
	else cout << -1 << endl;
	return 0;
}
