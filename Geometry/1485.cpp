#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, x, y;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		vector<pair<int, int>> v;
		vector<int> s;
		for(int j = 0; j < 4; j++){
			cin >> x >> y;
			v.push_back({x, y});
		}
		for(int j = 0; j < 4; j++){
			for(int z = j + 1; z < 4; z++){
				s.push_back(pow(v[j].second - v[z].second, 2) + pow(v[j].first - v[z].first, 2));
			}
		}
		sort(s.begin(), s.end());
		if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[4] == s[5]) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
