#include <iostream>
#include <queue>
using namespace std;

int l, r, c, sx, sy, sz;
char map[30][30][30];
int visited[30][30][30];

int dx[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { -1, 1, 0, 0, 0, 0 };

void initialize() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			for (int k = 0; k < 30; k++) {
				visited[i][j][k] = 0;
			}
		}
	}
}

int bfs() {
	queue<pair<int, pair<int, int>>> q;
	visited[sx][sy][sz] = 1;
	q.push({ sx, {sy, sz} });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second.first;
		int cz = q.front().second.second;
		q.pop();

		if (map[cx][cy][cz] == 'E') {
			return visited[cx][cy][cz] - 1;
		}

		for (int i = 0; i < 6; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nz = cz + dz[i];

			if (map[nx][ny][nz] == '#') continue;
			if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c) continue;
			if (visited[nx][ny][nz] != 0) continue;

			q.push({ nx, {ny, nz} });
			visited[nx][ny][nz] = visited[cx][cy][cz] + 1;
		}
	}

	return -1;
}

int main() {
	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) return 0;

		initialize();

		string s;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> s;
				for (int k = 0; k < c; k++) {
					map[i][j][k] = s[k];
					if (s[k] == 'S') {
						sx = i;
						sy = j;
						sz = k;
					}
				}
			}
		}

		int res = bfs();
		if (res == -1) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << res << " minute(s)." << '\n';
	}
}
