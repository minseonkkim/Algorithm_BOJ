#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, k;
	cin >> n;
	
	vector<int> v;
	for(int i = 0; i < n; i++){	
		cin >> k;
		v.push_back(k);
	}
	
	sort(v.begin(), v.end());
	
	cin >> m;
	
	for(int i = 0; i < m; i++){	
		cin >> k;
		auto l = lower_bound(v.begin(), v.end(), k);
		auto u = upper_bound(v.begin(), v.end(), k);
		cout << u - l << '\n';
	}
	
	return 0;
}
