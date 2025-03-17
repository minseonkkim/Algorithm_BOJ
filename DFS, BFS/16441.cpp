#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
char map[100][100];
bool visited[100][100];
bool cango[100][100];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void memo(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!cango[i][j] && visited[i][j]) cango[i][j] = true;
		}
	}
}

void bfs(int sx, int sy){
	memset(visited, sizeof(visited), false);
	
	queue<pair<int, int>> q;
	q.push({sx, sy});
	visited[sx][sy] = true;
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
		
			if(map[nx][ny] == '+'){
				while(true){
					if(map[nx][ny] == '.' || map[nx + dx[i]][ny + dy[i]] == '#') break;
					
					nx += dx[i];
					ny += dy[i];
				}
			}
			
			if(visited[nx][ny] || map[nx][ny] == '#') continue;
			
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == 'W') {
				bfs(i, j);
				memo();
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == '.' && !cango[i][j]) cout << 'P';
			else cout << map[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}
