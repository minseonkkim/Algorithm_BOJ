#include <iostream>
using namespace std;

int r, c, k, cnt;
char map[5][5];
bool visited[5][5];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void dfs(int x, int y, int dis){
	if(dis > k) return;
	
	if(x == 0 && y == c - 1){
		if(dis == k) cnt++;
		return;
	}
	
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if(map[nx][ny] == 'T' || visited[nx][ny]) continue;
		
		visited[nx][ny] = true;
		dfs(nx, ny, dis + 1);
		visited[nx][ny] = false;
	}
}

int main() {
	cin >> r >> c >> k;
	for(int i = 0; i < r; i++){
		string s;
		cin >> s;
		for(int j = 0; j < c; j++){
			map[i][j] = s[j];
		}
	}
	visited[r - 1][0] = true;
	dfs(r - 1, 0, 1);
	cout << cnt;
	return 0;
}
