#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int before[30][30];
int after[30][30];
bool visited[30][30];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(int sx, int sy){
	queue<pair<int, int>> q;
	q.push({sx, sy});
	visited[sx][sy] = true;
	
	int beforenum = before[sx][sy];
	int afternum = after[sx][sy];
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		before[cx][cy] = afternum;
		
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(before[nx][ny] != beforenum || visited[nx][ny]) continue;
			
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
			cin >> before[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> after[i][j];
		}
	}
	
	bool injected = false;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(before[i][j] != after[i][j]) {
				bfs(i, j);
				injected = true;
				break;
			}
		}
		if(injected) break;
	}
	
	bool issame = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(before[i][j] != after[i][j]) {
				issame = false;
				break;
			}
		}
		if(!issame) break;
	}
	if(issame) cout << "YES";
	else cout << "NO";
	return 0;
}
