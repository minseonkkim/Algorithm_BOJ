#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int m, n, h;
int arr[100][100][100];
int dist[100][100][100];
queue<pair<int, pair<int, int>>> q;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

void bfs(){
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second.first;
		int cz = q.front().second.second;
		q.pop();
		
		for(int i = 0; i < 6; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nz = cz + dz[i];
			
			if(!(nx >= 0 && ny >= 0 && nz >= 0 && nx < h && ny < n && nz < m)) continue;
			if(dist[nx][ny][nz] == -1){
				dist[nx][ny][nz] = dist[cx][cy][cz] + 1;
				q.push({nx, {ny, nz}});
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m >> n >> h;
	int cnt = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				cin >> arr[i][j][k];
				if(arr[i][j][k] == 0) {
					cnt++;
					dist[i][j][k] = -1;
				}
				else if(arr[i][j][k] == 1) q.push({i, {j, k}});
			}
		}
	}
	
	if(cnt == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	bfs();
	
	int day = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				if(dist[i][j][k] == -1){
					cout << -1 << endl;
					return 0;
				}
				day = max(day, dist[i][j][k]);
			}
		}
	}
	cout << day << endl;
	return 0;
}
