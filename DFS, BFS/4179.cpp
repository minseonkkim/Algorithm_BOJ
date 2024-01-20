#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int r, c;
int answer = 0;
char map[1000][1000];
queue<pair<int, int>> fireq;
queue<pair<int, int>> jq;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(){
	while(!jq.empty()){
		//for(int i = 0; i < r; i++){
		//	for(int j = 0; j < c; j++){
		//		cout << map[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		
		answer++;
		
		// 불 확장
		int fire_cnt = fireq.size();
		for(int i = 0; i < fire_cnt; i++){
			int cx = fireq.front().first;
			int cy = fireq.front().second;
			fireq.pop();
			
			for(int i = 0; i < 4; i++){
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				
				if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
				if(map[nx][ny] == '.'){
					map[nx][ny] = '*';
					fireq.push({nx, ny});
				}
			}
		}
		
		// 고슴도치 이동
		int j_cnt = jq.size();
		for(int i = 0; i < j_cnt; i++){
			int cx = jq.front().first;
			int cy = jq.front().second;
			jq.pop();
			
			if(cx == 0 || cy == 0 || cx == r - 1 || cy == c - 1){
				cout << answer;
				return;
			}
		
			for(int i = 0; i < 4; i++){
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				
			
				if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
				if(map[nx][ny] == '.'){
					jq.push({nx, ny});
					map[nx][ny] = 'S';
				}
			}
		}
	}
	cout << "IMPOSSIBLE";
	return;
}

int main() {
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		string s;
		cin >> s;
		for(int j = 0; j < c; j++){
			map[i][j] = s[j];
			if(s[j] == 'J'){
				jq.push({i, j});
			} else if(s[j] == 'F'){
				fireq.push({i, j});
			}
		}
	}
	bfs();
	return 0;
}
