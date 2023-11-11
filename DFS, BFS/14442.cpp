#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
char map[1001][1001];
int visited[1001][1001][11];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int bfs(int x, int y){
	queue<pair<int, pair<int, int>>> q;
	q.push({0, {x, y}});
	visited[x][y][0] = 1;
	
	while(!q.empty()){
		int wall = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		if(x == n && y == m){
			return visited[x][y][wall];
		}
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			
			if(map[nx][ny] == '0' && visited[nx][ny][wall] == 0){
				visited[nx][ny][wall] = visited[x][y][wall] + 1;
				q.push({wall, {nx, ny}});
			} else if(map[nx][ny] == '1' && wall < k && visited[nx][ny][wall + 1] == 0){
				visited[nx][ny][wall + 1] = visited[x][y][wall] + 1;
				q.push({wall + 1, {nx, ny}});
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> map[i][j];
		}
	}
	cout << bfs(1, 1);
	return 0;
}
