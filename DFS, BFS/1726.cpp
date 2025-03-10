#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, answer = 987654321;
int map[101][101];
bool visited[101][101][5];

int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

pair<pair<int, int>, int> startp, endp;

int change_dir(int cd, char c){
	if(c == 'L'){
		if(cd == 1) return 4;
		else if(cd == 2) return 3;
		else if(cd == 3) return 1;
		else return 2;
	} else if(c == 'R'){
		if(cd == 1) return 3;
		else if(cd == 2) return 4;
		else if(cd == 3) return 2;
		else return 1;
	}
}

void bfs(){
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({{startp.first.first, startp.first.second}, {startp.second, 0}});
	visited[startp.first.first][startp.first.second][startp.second] = true;
	
	while(!q.empty()){
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cd = q.front().second.first;
		int ccnt = q.front().second.second;
		q.pop();
		
		if(cx == endp.first.first && cy == endp.first.second && cd == endp.second){
			answer = min(answer, ccnt);
			break;
		}
		
		for(int i = 1; i <= 3; i++){
			int nx = cx + dx[cd] * i;
			int ny = cy + dy[cd] * i;
			
			if(map[nx][ny] == 1) break;
			if(nx <= 0 || nx > m || ny <= 0 || ny > n) continue;
			if(visited[nx][ny][cd]) continue;
			
			q.push({{nx, ny}, {cd, ccnt + 1}});
			visited[nx][ny][cd] = true;
		}
		
		int nd = change_dir(cd, 'L');
		if(!visited[cx][cy][nd]){
			visited[cx][cy][nd] = true;
			q.push({{cx, cy}, {nd, ccnt + 1}});
		}
		nd = change_dir(cd, 'R');
		if(!visited[cx][cy][nd]){
			visited[cx][cy][nd] = true;
			q.push({{cx, cy}, {nd, ccnt + 1}});
		}
	}
}

int main() {
	cin >> m >> n;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> map[i][j];
		}
	}
	cin >> startp.first.first >> startp.first.second >> startp.second;
	cin >> endp.first.first >> endp.first.second >> endp.second;
	
	bfs();
	cout << answer;
	return 0;
}
