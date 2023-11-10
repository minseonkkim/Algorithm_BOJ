#include <iostream>
#include <queue>
using namespace std;

int n, m, hx, hy, ex, ey;
int map[1001][1001];
int visited[1001][1001][2];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool bfs(int x, int y){
	queue<pair<int, pair<int, int>>> q;  // {벽 뚫기 여부, {x, y}}
	q.push({1, {x, y}});  // 벽을 뚫을 수 있으면 1
	visited[x][y][1] = 1;
	
	while(!q.empty()){
		int bore = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		if(x == ex && y == ey){
			cout << visited[x][y][bore] - 1;
			return true;
		}
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			if(map[nx][ny] == 1 && bore == 1){
				visited[nx][ny][0] = visited[x][y][bore] + 1;
				q.push({0, {nx, ny}});
			}else if(map[nx][ny] == 0 && !visited[nx][ny][bore]){
				visited[nx][ny][bore] = visited[x][y][bore] + 1;
				q.push({bore, {nx, ny}});
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m >> hx >> hy >> ex >> ey;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> map[i][j];
		}
	}
	bool b = bfs(hx, hy);
	if(!b) cout << -1;
	return 0;
}
