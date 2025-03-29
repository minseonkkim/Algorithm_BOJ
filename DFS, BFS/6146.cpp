#include <iostream>
#include <queue>
using namespace std;

int x, y, n;
int map[1001][1001];
bool visited[1001][1001];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(){
	queue<pair<pair<int, int>, int>> q;
	q.push({{500, 500}, 0});
	visited[500][500] = true;
	
	while(!q.empty()){
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		
		if(cx == x + 500 && cy == y + 500){
			cout << cnt;
			return;
		}
		
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 0 || nx > 1000 || ny < 0 || ny > 1000) continue;
			if(visited[nx][ny] || map[nx][ny] == 1) continue;
			
			visited[nx][ny] = true;
			q.push({{nx, ny}, cnt + 1});
		}
	}
}

int main() {
	cin >> x >> y >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		map[a + 500][b + 500] = 1;
	}
	bfs();
	return 0;
}
