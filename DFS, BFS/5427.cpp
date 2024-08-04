#include <iostream>
#include <queue>
using namespace std;

int tc, w, h, time_cnt;
char building[1000][1000];
queue<pair<int, int>> sq;
queue<pair<int, int>> fq;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void init() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			building[i][j] = '.';
		}
	}
	
	while (!sq.empty()) {
		sq.pop();
	}
	while (!fq.empty()) {
		fq.pop();
	}
}

void moveF() {
	int fire_num = fq.size();

	for (int i = 0; i < fire_num; i++) {
		int cx = fq.front().first;
		int cy = fq.front().second;
		fq.pop();

		for (int j = 0; j < 4; j++) {
			int nx = cx + dx[j];
			int ny = cy + dy[j];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (building[nx][ny] != '.') continue;

			building[nx][ny] = '*';
			fq.push({ nx, ny });
		}
	}
}

int moveS() {
	int time = 0;
	while (!sq.empty()) {
		time++;
		moveF();

		int sg_cnt = sq.size();
		for (int i = 0; i < sg_cnt; i++) {
			int cx = sq.front().first;
			int cy = sq.front().second;
			sq.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) return time;

				if (building[nx][ny] == '.') {
					sq.push({ nx, ny });
					building[nx][ny] = '@';
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> tc;
	
	for (int t = 0; t < tc; t++) {
		cin >> w >> h;

		string s;
		for (int i = 0; i < h; i++) {
			cin >> s;
			for (int j = 0; j < w; j++) {
				building[i][j] = s[j];
				if (s[j] == '@') {
					sq.push({ i, j });
				}
				else if (s[j] == '*') {
					fq.push({ i, j });
				}
			}
		}

		int res = moveS();
		if (res == -1) cout << "IMPOSSIBLE\n";
		else cout << res << '\n';

		init();
	}
}
