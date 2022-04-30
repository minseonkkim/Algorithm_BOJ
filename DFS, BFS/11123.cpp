#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int t, h, w, cnt = 0;
char arr[100][100];
bool visited[100][100];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void bfs(int a, int b){
	queue<pair<int, int>> q;
	q.push({a, b});
	visited[a][b] = true;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!(nx >= 0 && nx < h && ny >= 0 && ny < w)) continue;
			
			if(!visited[nx][ny] && arr[nx][ny] == '#'){
				q.push({nx, ny});
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	for(int i = 0; i < t; i++){
		cnt = 0;
		memset(visited, false, sizeof(visited));
		cin >> h >> w;
		for(int p = 0; p < h; p++){
			for(int q = 0; q < w; q++){
				cin >> arr[p][q];
			}
		}
		
		for(int p = 0; p < h; p++){
			for(int q = 0; q < w; q++){
				if(arr[p][q] == '#' && !visited[p][q]) {
					bfs(p, q);
					cnt++;
				}
			}
		}
		
		cout << cnt << endl;
	}
	return 0;
}
