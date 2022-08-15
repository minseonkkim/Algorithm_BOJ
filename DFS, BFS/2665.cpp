#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
int arr[50][50];
int visited[50][50];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(){
	queue<pair<int, pair<int, int>>> q;
	q.push({0, {0, 0}});
	
	while(!q.empty()){
		int cnt = q.front().first;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;
			
			if(visited[nx][ny] > cnt){
				if(arr[nx][ny] == 0){
					q.push({cnt + 1, {nx, ny}});
					visited[nx][ny] = cnt + 1;
				} else{
					q.push({cnt, {nx, ny}});
					visited[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		for(int j = 0; j < n; j++){
			arr[i][j] = str[j] - '0';
			visited[i][j] = 987654321;
		}
	}
	bfs();
	cout << visited[n - 1][n - 1] << endl;
	return 0;
}
