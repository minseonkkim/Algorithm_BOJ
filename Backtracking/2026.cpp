#include <iostream>
#include <vector>
using namespace std;

int k, n, f;
bool isFriend[901][901];
vector<int> check;

void dfs(int idx) {
	if (check.size() == k) {
		for (int i = 0; i < check.size(); i++) {
			cout << check[i] << '\n';
		}
		exit(0);
	}
	for (int i = idx + 1; i <= n; i++) {
		if (!isFriend[idx][i]) continue;

		bool flag = true;
		for (int j = 0; j < check.size(); j++) {
			if (!isFriend[i][check[j]]) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;

		check.push_back(i);
		dfs(i);
		check.pop_back();
	}
}

int main() {
	cin >> k >> n >> f;
	for (int i = 0; i < f; i++) {
		int a, b;
		cin >> a >> b;
		isFriend[a][b] = true;
		isFriend[b][a] = true;
	}
	for (int i = 1; i <= n; i++) {
		check.push_back(i);
		dfs(i);
		check.pop_back();
	}
	cout << -1 << '\n';
}
