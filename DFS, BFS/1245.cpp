#include <iostream>
using namespace std;

int n, m;
int arr[100][70];
int visited[100][70];
bool isPeak = true;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void dfs(int x, int y){
	visited[x][y] = true;
	for(int i = 0; i < 8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!(nx >= 0 && ny >= 0 && nx < n && ny < m)) continue;
		
		// 인접한 칸에 더 높은 봉우리가 있는가?
		if(arr[x][y] < arr[nx][ny]) isPeak = false;
		
		if(!visited[nx][ny] && arr[x][y] == arr[nx][ny]){
			visited[nx][ny] = true;
			dfs(nx, ny);
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
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j]){
				isPeak = true;
				dfs(i, j);
				if(isPeak) answer += 1;
			}
		}
	}
	
	cout << answer << endl;
	return 0;
}
