#include <iostream>
#include <queue>
using namespace std;

int arr[300][300];
int tmp[300][300];
bool visited[300][300];
int n, m;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void init(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			visited[i][j] = false;
		}
	}	
}

void melt(int a, int b){
	int c = 0;
	if(a - 1 >= 0 && arr[a - 1][b] == 0) c++;
	if(a + 1 < n && arr[a + 1][b] == 0) c++;
	if(b - 1 >= 0 && arr[a][b - 1] == 0) c++;
	if(b + 1 < m && arr[a][b + 1] == 0) c++;
	tmp[a][b] = arr[a][b] - c;
	if(tmp[a][b] < 0) tmp[a][b] = 0;
}

void bfs(int a, int b){
	queue<pair<int, int>> q;
	q.push({a, b});
	visited[a][b] = true;
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(!(nx >= 0 && ny >= 0 && nx < n && ny < m)) continue;
			
			if(arr[nx][ny] != 0 && !visited[nx][ny]){
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	int year = 0;
	while(true){
		init();
		
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(arr[i][j] != 0 && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		if(cnt >= 2) break;
		if(cnt == 0){
			year = 0;
			break;
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(arr[i][j] == 0) tmp[i][j] = 0;
				else melt(i, j);
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				arr[i][j] = tmp[i][j];
			}
		}
		
		year++;
	}
	cout << year << endl;
	return 0;
}
