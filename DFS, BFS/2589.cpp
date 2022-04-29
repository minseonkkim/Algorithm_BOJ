#include <iostream>
#include <queue>
using namespace std;

int n, m;
char arr[50][50];
int path[50][50] = {-1, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int maxlen = 0;

void bfs(int x, int y){
	queue<pair<int, int>> q;
	q.push({x, y});
	path[x][y] = 0;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)) continue;
			
			if(path[nx][ny] == -1 && arr[nx][ny] == 'L'){
				path[nx][ny] = path[x][y] + 1;
				q.push({nx, ny});
				if(maxlen < path[nx][ny]) maxlen = path[nx][ny];
			}
		}
	}
}

void reset(){
	maxlen = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			path[i][j] = -1;
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
	
	// 모든 'L'에 대하여 bfs 실행
	int answer = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr[i][j] == 'L') {
				bfs(i, j);
				if(maxlen > answer) answer = maxlen;
				reset();
			}
		}
	}
	cout << answer << endl;
	return 0;
}
