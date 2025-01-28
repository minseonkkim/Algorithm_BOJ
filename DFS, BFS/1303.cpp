#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, m;
char map[100][100];
bool visited[100][100];
int answer[2];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int bfs(int x, int y){
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[x][y] = true;
	int cnt = 1;
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if(visited[nx][ny] || map[nx][ny] != map[cx][cy]) continue;
			
			visited[nx][ny] = true;
			q.push({nx, ny});
			cnt++;
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	cin.ignore();
	for(int i = 0; i < m; i++){
		string str;
		getline(cin, str);
		for(int j = 0; j < n; j++){
			map[i][j] = str[j];
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]) {
				int cnt = bfs(i, j);
				if(map[i][j] == 'W') answer[0] += pow(cnt, 2);
				else answer[1] += pow(cnt, 2);
			}
		}
	}
	
	cout << answer[0] << " " << answer[1];
	return 0;
}
