#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> tree[10001];
bool visited[10001];

int max_len = 0;
int end_node = 0;

void dfs(int node, int len) {
	if (visited[node]) return;
	visited[node] = true;

	if (len > max_len) {
		max_len = len;
		end_node = node;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		dfs(tree[node][i].first, len + tree[node][i].second);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}

	dfs(1, 0);  // 임의의 정점에서 가장 먼 정점 찾기
	max_len = 0;
	for (int i = 0; i < 10001; i++) visited[i] = false;
	dfs(end_node, 0);  // 위에서 찾은 정점에서 가장 먼 정점 찾기
	cout << max_len << '\n';
}
