#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int map[200][200];
bool visited[200][200];
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
 
int bfs(int cx, int cy, int nx, int ny){
	queue<pair<int, int>> q;
	q.push({cx, cy});
	visited[cx][cy] = true;
 
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		if(x == nx && y == ny){
			return map[x][y];
		}
		q.pop();
 
		for(int i = 0; i < 6; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
 
			if(xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
			if(visited[xx][yy]) continue;
 
			visited[xx][yy] = true;
			map[xx][yy] = map[x][y] + 1;
			q.push({xx, yy});
		}
	}
	return -1;
}
 
int main() {
	int cx, cy, nx, ny;
	cin >> n >> cx >> cy >> nx >> ny;
 
	cout << bfs(cx, cy, nx, ny);

	return 0;
}
