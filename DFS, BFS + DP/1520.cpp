#include <iostream>
using namespace std;

int m, n;
int map[500][500];
int dp[500][500];

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int dfs(int x, int y) {
	if (x == m - 1 && y == n - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (map[nx][ny] >= map[x][y]) continue;

		dp[x][y] += dfs(nx, ny);
	}
	return dp[x][y];
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs(0, 0);
	return 0;
}
