#include <iostream>
#include <queue>
using namespace std;

int n, m, k, maxg;
int arr[101][101];
bool visited[101][101];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(int a, int b){
	queue<pair<int, int>> q;
	q.push({a, b});
	visited[a][b] = true;
	int cnt = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!(nx > 0 && ny > 0 && nx <= n && ny <= m)) continue;
			
			if(arr[nx][ny] == 1 && !visited[nx][ny]){
				visited[nx][ny] = true;
				q.push({nx, ny});
				cnt++;
			}
		}
		
		if(cnt > maxg) maxg = cnt;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		int r, c;
		cin >> r >> c;
		arr[r][c] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(arr[i][j] == 1 && !visited[i][j]){
				bfs(i, j);
			}
		}
	}
	
	cout << maxg << endl;
	return 0;
}
