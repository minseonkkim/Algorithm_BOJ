#include<iostream>
#include<cmath>
using namespace std;

int r, c, t;
int map[50][50];
int copymap[50][50];
int cleaner[2];

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void spread(int x, int y) {
	int amt = floor(map[x][y] / 5);
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (map[nx][ny] == -1) continue;
		cnt++;
		copymap[nx][ny] += amt;
	}
	copymap[x][y] -= amt * cnt;
}

int main(){
	cin >> r >> c >> t;
	bool flag = false;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1 && !flag) {
				flag = true;
				cleaner[0] = i;
			}
			else if (map[i][j] == -1 && flag) {
				cleaner[1] = i;
			}
		}
	}
	int time = 0;
	while (true) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				copymap[i][j] = map[i][j];
			}
		}
		time++;

		// 미세먼지 확산
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] > 0) spread(i, j);
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				map[i][j] = copymap[i][j];
			}
		}

		// 공기청정기 작동
		// 위쪽 공기청정기
		for (int i = cleaner[0] - 1; i > 0; i--) {
			map[i][0] = map[i - 1][0];
		}
		for (int i = 0; i < c - 1; i++) {
			map[0][i] = map[0][i + 1];
		}
		for (int i = 0; i <= cleaner[0] - 1; i++) {
			map[i][c - 1] = map[i + 1][c - 1];
		}
		for (int i = c - 1; i >= 2; i--) {
			map[cleaner[0]][i] = map[cleaner[0]][i - 1];
		}
		map[cleaner[0]][1] = 0;

		// 아래쪽 공기청정기
		for (int i = cleaner[1] + 1; i < r - 1; i++) {
			map[i][0] = map[i + 1][0];
		}
		for (int i = 0; i < c - 1; i++) {
			map[r - 1][i] = map[r - 1][i + 1];
		}
		for (int i = r - 1; i >= cleaner[1] + 1; i--) {
			map[i][c - 1] = map[i - 1][c - 1];
		}
		for (int i = c - 1; i >= 2; i--) {
			map[cleaner[1]][i] = map[cleaner[1]][i - 1];
		}
		map[cleaner[1]][1] = 0;

		if (time == t) {
			break;
		}
	}
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == -1) continue;
			ans += map[i][j];
		}
	}
	cout << ans;
}
