#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[501][501];
bool visited[501][501];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int bfs(int a, int b){
	queue<pair<int, int>> q;
	q.push({a, b});
	visited[a][b] = true;
	int area = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!(nx >= 1 && ny >= 1 && nx <= n && ny <= m)) continue;
			
			if(!visited[nx][ny] && map[nx][ny] == 1){
				visited[nx][ny] = true;
				q.push({nx, ny});
				area++;
			}
		}
	}
	return area;
}

int main() {
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> map[i][j];
		}
	}
	
	int cnt = 0, maxarea = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!visited[i][j] && map[i][j] == 1){
				maxarea = max(bfs(i, j), maxarea);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	cout << maxarea << endl;
	return 0;
}
