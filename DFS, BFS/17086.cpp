#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[50][50];
bool visited[50][50];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int bfs(int x, int y){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			visited[i][j] = false;
		}
	}
	
	queue<pair<pair<int, int>, int>> q;
	q.push({{x, y}, 0});
	visited[x][y] = true;
	
	while(!q.empty()){
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		
		if(map[cx][cy] == 1){
			return cnt;
		}
		
		for(int i = 0; i < 8; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(visited[nx][ny]) continue;
			
			visited[nx][ny] = true;
			q.push({{nx, ny}, cnt + 1});
		}
	}
	return 0;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
	int answer = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == 0){
				int dist = bfs(i, j);
				answer = max(answer, dist);
			}
		}
	}
	cout << answer;
	return 0;
}
