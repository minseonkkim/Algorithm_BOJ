#include <iostream>
#include <algorithm>
using namespace std;

int n;
int map[500][500];
int dp[500][500];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int dfs(int x, int y){
	if(dp[x][y] != 0) return dp[x][y];
	dp[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		
		if(map[nx][ny] > map[x][y]){
			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
		}
	}
	return dp[x][y];
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans;
	return 0;
}
