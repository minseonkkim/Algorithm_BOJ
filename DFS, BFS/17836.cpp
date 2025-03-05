#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, t, mincnt = 987654321;
int map[101][101];
bool visited[101][101][2];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(){
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({{1, 1}, {0, 0}});
	visited[1][1][0] = true;
	
	while(!q.empty()){
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int ccnt = q.front().second.first;
		int find = q.front().second.second;
		q.pop();
		
		if(cx == n && cy == m){
			mincnt = min(mincnt, ccnt);
			break;
		}
		
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx <= 0 || nx > n || ny <= 0 || ny > m || visited[nx][ny][find]) continue;
			if(find == 0 && map[nx][ny] == 1) continue;
			
			visited[nx][ny][find] = true;
			if(map[nx][ny] == 2 || find == 1) q.push({{nx, ny}, {ccnt + 1, 1}});
			else q.push({{nx, ny}, {ccnt + 1, 0}});
		}
	}
}

int main() {
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> map[i][j];
		}
	}
	bfs();
	
	if(mincnt > t) cout << "Fail";
	else cout << mincnt;
	return 0;
}
