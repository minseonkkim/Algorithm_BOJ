#include <iostream>
#include <cstring>
using namespace std;

int n, m, k, ans;
string word;
char map[100][100];
int dp[100][100][80];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int dfs(int x, int y, int idx){
	if(dp[x][y][idx] != -1) return dp[x][y][idx];
	if(idx == word.length()) return 1;
	
	dp[x][y][idx] = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 1; j <= k; j++){
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			
			if(map[nx][ny] == word[idx]){
				dp[x][y][idx] += dfs(nx, ny, idx + 1);
			}
		}
	}
	return dp[x][y][idx];
}

int main() {
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
	cin >> word;

	memset(dp, -1, sizeof(dp));
	
	char start = word[0];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == start){
				ans += dfs(i, j, 1);
			}
		}
	}
	
	cout << ans;
	return 0;
}
