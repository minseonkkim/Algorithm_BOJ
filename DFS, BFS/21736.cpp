#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[601][601];
bool visit[601][601];
int cnt = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int i, int j) {
	visit[i][j] = true;

	queue<pair<int, int>> q;
	q.push(pair<int, int>(i, j));

	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = nx + dx[i];
			int y = ny + dy[i];

			if (x >= 0 && y >= 0 && x < n && y < m && visit[x][y] == false) {
				if (map[x][y] == 'X') continue;
				if (map[x][y] == 'P') cnt++;
				visit[x][y] = true;
				q.push(pair<int, int>(x, y));
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'I') {
				bfs(i, j);
			}
		}
	}
	if (cnt == 0) cout << "TT" << endl;
	else cout << cnt << endl;
	return 0;
}
