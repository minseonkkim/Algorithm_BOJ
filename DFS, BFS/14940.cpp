#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[1000][1000];
bool visited[1000][1000];
int ans[1000][1000];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(int a, int b){
	queue<pair<int, int>> q;
	q.push({a, b});
	visited[a][b] = true;
	ans[a][b] = 0;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)) continue;
			
			if(arr[nx][ny] != 0 && !visited[nx][ny]){
				q.push({nx, ny});
				visited[nx][ny] = true;
				ans[nx][ny] = ans[x][y] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr[i][j] == 2) {
				bfs(i, j);
				break;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr[i][j] == 0) cout << 0 << " ";
			else if(arr[i][j] == 1 && ans[i][j] == 0) cout << -1 << " ";
			else cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
