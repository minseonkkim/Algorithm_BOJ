#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n, v;
int map[1001][1001];
int visit[1001];

void reset() {
	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
	}
}

void dfs() {
	stack<int> s;
	s.push(v);

	while (!s.empty()) {
		int node = s.top();
		s.pop();
		if(!visit[node]) cout << node << " ";
		visit[node] = 1;

		for (int i = n; i > 0; i--) {
			if (!visit[i] && map[node][i] == 1) {
				s.push(i);
			}
		}
	}
	cout << endl;
}

void bfs() {
	visit[v] = 1;
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		int node = q.front();
		cout << node << " ";
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (!visit[i] && map[node][i] == 1) {
				q.push(i);
				visit[i] = 1;
			}
		}
	}
	cout << endl;
}

int main() {
	int m, n1, n2;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		map[n1][n2] = map[n2][n1] = 1;
	}

	dfs();
	reset();
	bfs();
	return 0;
}
