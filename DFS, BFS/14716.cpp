#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[250][250];
bool visited[250][250];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push({i, j});
	visited[i][j] = true;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!(nx >= 0 && ny >= 0 && nx < n && ny < m)) continue;
			if(arr[nx][ny] == 1 && !visited[nx][ny]){
				visited[nx][ny] = true;
				q.push({nx, ny});
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
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr[i][j] == 1 && !visited[i][j]){
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
