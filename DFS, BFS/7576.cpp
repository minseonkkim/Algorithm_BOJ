#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001

int N, M;
int arr[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue <pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && arr[nx][ny] == 0) {
				arr[nx][ny] = arr[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int cnt = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({i, j});
			}
		}
	}
	
	
	bfs();
	
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				cout << -1 << endl; 
				return 0;
			}
			if(cnt < arr[i][j]) 
				cnt = arr[i][j];
		}
	}
	

	cout << cnt - 1 << endl;
	return 0;
}
