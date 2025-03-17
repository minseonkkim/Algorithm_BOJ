#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r1, c1, r2, c2;
char map[501][501];
bool visited[501][501];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(){
	queue<pair<int, int>> q;
	q.push({r1, c1});
	visited[r1][c1] = true;
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		if(cx == r2 && cy == c2 && map[cx][cy] == 'X'){
			cout << "YES";
			return;
		}
		
		map[cx][cy] = 'X';
		
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx == r2 && ny == c2){
				q.push({nx, ny});
			} else{
				if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
				if(map[nx][ny] == 'X' || visited[nx][ny]) continue;
				
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
	cout << "NO";
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> map[i][j];
		}
	}
	cin >> r1 >> c1 >> r2 >> c2;
	
	map[r1][c1] = '.';
	
	bfs();
	
	return 0;
}
