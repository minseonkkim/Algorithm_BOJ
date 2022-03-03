#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int n, num;
	vector<pair<int, int>> v;
	stack<pair<int, int>> s;
	vector<int> res;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back({ i + 1, num });
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		if (s.empty()) res.push_back(-1);
		else {
			if(v[i].second == s.top().second) s.pop();
			if(!s.empty()) res.push_back(s.top().first);
			else res.push_back(-1);
		}
		s.push({ v[i].first, v[i].second });
	}

	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i] << " ";
	}

	return 0;
}
