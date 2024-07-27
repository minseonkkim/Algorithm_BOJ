#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n;
int map[1000][1000];
bool visited[1000][1000];

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void bfs(int start) {
	queue<pair<int, int>> q;
	visited[0][start] = true;
	q.push({ 0, start });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (visited[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			
			if (map[nx][ny] == 0) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
			
		}
	}
}

int main() {
	cin >> m >> n;
	string s;
	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		if (map[0][i] == 0 && !visited[0][i]) {
			bfs(i);
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (visited[m - 1][i]) {
			cnt++;
		}
	}

	if (cnt != 0) cout << "YES";
	else cout << "NO";
}
