#include <iostream>
using namespace std;
 
int n, m;
char map[500][500];
int dp[500][500];
int answer;
 
int dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return 1;
	if (dp[x][y] != -1) return dp[x][y];
 
	dp[x][y] = 0;
 
	int nx, ny;
	if (map[x][y] == 'U') {
		nx = x - 1;
		ny = y;
	}
	else if (map[x][y] == 'R') {
		nx = x;
		ny = y + 1;
	}
	else if (map[x][y] == 'D') {
		nx = x + 1;
		ny = y;
	}
	else {
		nx = x;
		ny = y - 1;
	}
 
	dp[x][y] = dfs(nx, ny);
 
	return dp[x][y];
}
 
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answer += dfs(i, j);
		}
	}
	cout << answer;
	return 0;
}
