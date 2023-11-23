#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;
vector<int> a, b, v, w;

int main() {
	cin >> t;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		b.push_back(x);
	}
	
	for(int i = 0; i < n; i++){
		int sum = a[i];
		v.push_back(sum);
		for(int j = i + 1; j < n; j++){
			sum += a[j];
			v.push_back(sum);
		}
	}
	for(int i = 0; i < m; i++){
		int sum = b[i];
		w.push_back(sum);
		for(int j = i + 1; j < m; j++){
			sum += b[j];
			w.push_back(sum);
		}
	}
	
	sort(w.begin(), w.end());
	
	long long ans = 0;
	for(int i = 0; i < v.size(); i++){
		int diff = t - v[i];
		auto ub = upper_bound(w.begin(), w.end(), diff);
		auto lb = lower_bound(w.begin(), w.end(), diff);
		ans += (ub - lb);
	}
	cout << ans;
	return 0;
}
