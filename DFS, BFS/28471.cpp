#include <iostream>
#include <queue>
using namespace std;

int N, answer;
char map[2001][2001];
bool visited[2001][2001];

int dx[7] = {-1, 0, 0, -1, -1, 1, 1};
int dy[7] = {0, -1, 1, -1, 1, -1, 1};

void bfs(int sx, int sy){
	queue<pair<int, int>> q;
	q.push({sx, sy});
	visited[sx][sy] = true;
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for(int i = 0; i < 7; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if(visited[nx][ny] || map[nx][ny] == '#') continue;
			
			visited[nx][ny] = true;
			q.push({nx, ny});
			answer++;
		}
	}
}

int main() {
	cin >> N;
	int sx, sy;
	for(int i = 0; i < N; i++){
		string str;
		cin >> str;
		for(int j = 0; j < N; j++){
			map[i][j] = str[j];
			if(map[i][j] == 'F'){
				sx = i;
				sy = j;
			}
		}
	}
	
	bfs(sx, sy);
	cout << answer;
	return 0;
}
