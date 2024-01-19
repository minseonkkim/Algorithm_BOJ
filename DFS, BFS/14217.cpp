#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m, q;
bool street[501][501];
int answer[501];

void init() {
	for (int i = 0; i <= n; i++) {
		answer[i] = INF;
	}
}

void bfs() {
	queue<pair<int, int>> q;
	answer[1] = 0;
	q.push({1, 0});

	while (!q.empty()) {
		int cx = q.front().first;
		int ct = q.front().second;
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (cx == i) continue;
			if (street[cx][i] && answer[i] > ct + 1) {
				answer[i] = ct + 1;
				q.push({ i, ct + 1 });
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		street[a][b] = true;
		street[b][a] = true;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			street[b][c] = true;
			street[c][b] = true;
		}
		else if (a == 2) {
			street[b][c] = false;
			street[c][b] = false;
		}
		init();
		bfs();
		for (int i = 1; i <= n; i++) {
			if (answer[i] == INF) cout << -1 << " ";
			else cout << answer[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
