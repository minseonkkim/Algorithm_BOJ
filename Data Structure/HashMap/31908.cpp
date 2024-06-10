#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n;
map<string, vector<string>> m;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (b == "-") continue;
		m[b].push_back(a);
	}
	vector<pair<string, string>> ans;
	for (auto x : m) {
		if (x.second.size() == 2) {
			ans.push_back({ x.second[0], x.second[1] });
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x.first << ' ' << x.second << '\n';
	}
}
