#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int r, c, bx, by;
int answer = 0;
char map[50][50];
queue<pair<int, int>> waterq;
queue<pair<int, int>> sq;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(){
	while(!sq.empty()){
		//for(int i = 0; i < r; i++){
		//	for(int j = 0; j < c; j++){
		//		cout << map[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		
		answer++;
		
		// 물 확장
		int water_cnt = waterq.size();
		for(int i = 0; i < water_cnt; i++){
			int cx = waterq.front().first;
			int cy = waterq.front().second;
			waterq.pop();
			
			for(int i = 0; i < 4; i++){
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				
				if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
				if(map[nx][ny] == '.'){
					map[nx][ny] = '*';
					waterq.push({nx, ny});
				}
			}
		}
		
		// 고슴도치 이동
		int s_cnt = sq.size();
		for(int i = 0; i < s_cnt; i++){
			int cx = sq.front().first;
			int cy = sq.front().second;
			sq.pop();
		
			for(int i = 0; i < 4; i++){
				int nx = cx + dx[i];
				int ny = cy + dy[i];
			
				if(nx == bx && ny == by){
					cout << answer;
					return;
				}
			
				if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
				if(map[nx][ny] == '.'){
					sq.push({nx, ny});
					map[nx][ny] = 'S';
				}
			}
		}
	}
	cout << "KAKTUS";
	return;
}

int main() {
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		string s;
		cin >> s;
		for(int j = 0; j < c; j++){
			map[i][j] = s[j];
			if(s[j] == 'D'){
				bx = i;
				by = j;
			} else if(s[j] == 'S'){
				sq.push({i, j});
			} else if(s[j] == '*'){
				waterq.push({i, j});
			}
		}
	}
	bfs();
	return 0;
}
