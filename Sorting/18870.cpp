#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> tmp(v);
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

	for (int i = 0; i < n; i++) {
		auto idx = lower_bound(tmp.begin(), tmp.end(), v[i]);
		cout << idx - tmp.begin() << " ";
	}

	return 0;
}
