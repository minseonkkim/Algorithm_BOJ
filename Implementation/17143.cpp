#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark{
	int R;
	int C;
	int speed;
	int dir;
	int size;
};

int R, C, M, answer;
vector<int> map[101][101];
vector<Shark> sharks;

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

bool cmp(int a, int b){
	if(sharks[a].size > sharks[b].size) return true;
	return false;
}

void Fishing(int c){
	for(int i = 1; i <= R; i++){
		if(!map[i][c].empty()){
			answer += sharks[map[i][c][0]].size;
			sharks[map[i][c][0]].size = 0;
			map[i][c].clear();
			break;
		}
	}
}

void Move_Sharks(){
	for(int i = 0; i < sharks.size(); i++){
		if(sharks[i].size == 0) continue;
		int x = sharks[i].R;
		int y = sharks[i].C;
		map[x][y].clear();
	}
	
	for(int i = 0; i < sharks.size(); i++){
		if(sharks[i].size == 0) continue;
		
		int x = sharks[i].R;
		int y = sharks[i].C;
		int speed = sharks[i].speed;
		int dir = sharks[i].dir;
		
		
		if(dir == 1 || dir == 2){
			int rotate = (R - 1) * 2;
			if(speed >= rotate) speed %= rotate;
			
			for(int j = 0; j < speed; j++){
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if(nx < 1){
					dir = 2;
					nx += 2;
				}
				if(nx > R){
					dir = 1;
					nx -= 2;
				}
				x = nx;
				y = ny;
			}
		}else{
			int rotate = (C - 1) * 2;
			if(speed >= rotate) speed %= rotate;
			
			for(int j = 0; j < speed; j++){
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if(ny < 1){
					dir = 3;
					ny += 2;
				}
				if(ny > C){
					dir = 4;
					ny -= 2;
				}
				x = nx;
				y = ny;
			}
		}
		
		sharks[i].R = x;
		sharks[i].C = y;
		sharks[i].dir = dir;
		map[x][y].push_back(i);
	}
}

void Kill_Sharks(){
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			if(map[i][j].size() > 1){
				sort(map[i][j].begin(), map[i][j].end(), cmp);
				int live_shark = map[i][j][0];
				for(int k = 1; k < map[i][j].size(); k++){
					sharks[map[i][j][k]].size = 0;
					sharks[map[i][j][k]].R = -1;
					sharks[map[i][j][k]].C = -1;
				}
				map[i][j].clear();
				map[i][j].push_back(live_shark);
			}
		}
	}
}

int main() {
	cin >> R >> C >> M;
	for(int i = 0; i < M; i++){
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		map[r][c].push_back(i);
		sharks.push_back({r, c, s, d, z});
	}
	if(M == 0){
		cout << 0;
		return 0;
	}
	
	for(int i = 1; i <= C; i++){
		Fishing(i);
		Move_Sharks();
		Kill_Sharks();
	}
	cout << answer;
	return 0;
}
