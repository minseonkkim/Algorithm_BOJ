#include <iostream>
#include <queue>
using namespace std;

int map[5][5];
bool visited[5][5];
int r, c;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(){
	queue<pair<pair<int, int>, int>> q;
	q.push({{r, c}, 0});
	visited[r][c] = true;
	
	while(!q.empty()){
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		
		if(map[cx][cy] == 1){
			cout << cnt;
			return;
		}
		
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if(visited[nx][ny] || map[nx][ny] == -1) continue;
			
			visited[nx][ny] = true;
			q.push({{nx, ny}, cnt + 1});
		}
	}
	cout << -1;
}

int main() {
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> map[i][j];
		}
	}
	cin >> r >> c;
	bfs();
	return 0;
}
