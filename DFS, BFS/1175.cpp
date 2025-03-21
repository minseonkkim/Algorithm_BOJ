#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct block{
	int x, y;
	int dir, finc, find, cnt;
};

int n, m, sx, sy, answer = 987654321;
char map[50][50];
bool visited[50][50][4][2][2];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(){
	queue<block> q;
	for(int i = 0; i < 4; i++) {
		q.push({sx, sy, i, 0, 0, 0});
		visited[sx][sy][i][0][0] = true;
	}
	
	while(!q.empty()){
		int cx = q.front().x;
		int cy = q.front().y;
		int dir = q.front().dir;
		int finc = q.front().finc;
		int find = q.front().find;
		int cnt = q.front().cnt;
		q.pop();
		
		if(finc == 1 && find == 1){
			answer = min(answer, cnt);
			continue;
		}
		
		for(int i = 0; i < 4; i++){
			if(i == dir) continue;
			
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			int nc = finc, nd = find;
			if(map[nx][ny] == 'C') {
				if(nc == 1) continue;
				nc = 1;
			}
			if(map[nx][ny] == 'D') {
				if(nd == 1) continue;
				nd = 1;
			}
			if(visited[nx][ny][i][nc][nd] || map[nx][ny] == '#') continue;
			
			visited[nx][ny][i][nc][nd] = true;
			
			if(map[nx][ny] == 'C') q.push({nx, ny, i, 1, find, cnt + 1});
			else if (map[nx][ny] == 'D') q.push({nx, ny, i, finc, 1, cnt + 1});
			else q.push({nx, ny, i, finc, find, cnt + 1});
		} 
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	bool find = false;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			map[i][j] = s[j];
			if(s[j] == 'S'){
				sx = i;
				sy = j;
			} else if(s[j] == 'C'){
				if(!find){
					find = true;
				} else {
					map[i][j] = 'D';
				}
			}
		}
	}
	bfs();
	if(answer == 987654321) cout << -1;
	else cout << answer;
	return 0;
}
