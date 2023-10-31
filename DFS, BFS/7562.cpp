#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
 
int map[300][300];
bool visited[300][300];
int answer;
int dx[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
int dy[8] = {-1, -2, 1, 2, -1, -2, 1, 2};
 
void bfs(int l, int cx, int cy, int nx, int ny){
	queue<pair<int, int>> q;
	q.push({cx, cy});
	visited[cx][cy] = true;
 
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		if(x == nx && y == ny){
			answer = map[x][y];
			return;
		}
		q.pop();
 
		for(int i = 0; i < 8; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
 
			if(xx < 0 || yy < 0 || xx >= l || yy >= l) continue;
			if(visited[xx][yy]) continue;
 
			visited[xx][yy] = true;
			map[xx][yy] = map[x][y] + 1;
			q.push({xx, yy});
		}
	}
}
 
int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int l, cx, cy, nx, ny;
		cin >> l >> cx >> cy >> nx >> ny;
 
		bfs(l, cx, cy, nx, ny);
 
		cout << answer << '\n';
 
		for(int i = 0; i < 300; i++){
			for(int j = 0; j < 300; j++){
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
		answer = 0;
	}
	return 0;
}
