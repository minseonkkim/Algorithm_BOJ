#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[300][300];
bool visited[300][300];

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

void bfs(){
	queue<pair<int, int>> q;
	q.push({0, 0});
	visited[0][0] = true;
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		if(cx == m - 1 && cy == n - 1){
			cout << "Yes";
			return;
		}
		
		for(int i = 0; i < 2; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			
			if(!visited[nx][ny] && map[nx][ny] == 1){
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
	cout << "No";
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	bfs();
	return 0;
}
