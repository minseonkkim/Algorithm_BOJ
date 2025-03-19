#include <iostream>
#include <queue>
#include <deque>
using namespace std;

// 사과: A, 뱀: S

char map[101][101];
int n, k, l, didx;
queue<pair<int, char>> q;
deque<pair<int, int>> snake;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void trun(char dir){
	if(dir == 'D') {
		if(didx + 1 == 4) didx = 0;
		else didx++;
	}
	else {
		if(didx - 1 == -1) didx = 3;
		else didx--;
	}
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		map[x][y] = 'A';
	}
	cin >> l;
	for(int i = 0; i < l; i++){
		int x; char c; 
		cin >> x >> c;
		q.push({x, c});
	}
	
	snake.push_back({1, 1});
	int time = 0;
	while(true){
		time++; 
		int nx = snake.front().first + dx[didx];
		int ny = snake.front().second + dy[didx];
		if(nx <= 0 || nx > n || ny <= 0 || ny > n || map[nx][ny] == 'S'){
			cout << time;
			break;
		}
		if(map[nx][ny] != 'A') {
			map[snake.back().first][snake.back().second] = ' ';
			snake.pop_back();
		}
		map[nx][ny] = 'S';
		snake.push_front({nx, ny});
		
		if(!q.empty() && q.front().first == time){
			trun(q.front().second);
			q.pop();
		}
	}
	
	return 0;
}
