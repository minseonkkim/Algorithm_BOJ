#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int arr[100][100];
bool visited[100][100];
int n, m;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
int time, result;

bool bfs(){
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	visited[0][0] = true;
	time++;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)) continue;
			
			if(!visited[nx][ny]){
				// 인접한 칸이 0이면 계속 탐색
				if(arr[nx][ny] == 0){
					q.push({nx, ny});
				} 
				// 인접한 칸이 치즈면 0으로 바꾸고 카운팅
				else{
					arr[nx][ny] = 0;
					cnt++;
				}
				visited[nx][ny] = true;
			}
		}
	}
	
    // 치즈가 없다면 시간과, 이전 bfs에서 나온 치즈 개수 출력
	if(cnt == 0){
		cout << --time << endl;
		cout << result << endl;
		return true;
	} 
    // 치즈가 있다면 치즈의 개수 갱신
    else{
		result = cnt;
		return false;
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	while(true){
		if(bfs()) break;
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
