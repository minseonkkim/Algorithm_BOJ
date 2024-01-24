#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> map[2001];
bool visited[2001];
bool ans;

void dfs(int node, int depth) {
	if (depth == 4) {
		ans = true;
		return;
	}

	for (int i = 0; i < map[node].size(); i++) {
		int next = map[node][i];
		if (!visited[next]) {
			visited[next] = true;
			dfs(next, depth + 1);
			visited[next] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		visited[i] = true;
		dfs(i, 0);
		if (ans) break;
		visited[i] = false;
	}

	if (ans) cout << 1;
	else cout << 0;
}
