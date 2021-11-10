#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int r, c;
char map[20][20];
int alphabet[26] = { 0, };
int max_path = 0;

void dfs(int row, int col, int find_path) {
	max_path = max(find_path, max_path);

	for (int i = 0; i < 4; ++i) {
		int nx = row + dx[i];
		int ny = col + dy[i];

		if (0 <= nx && nx < r && 0 <= ny && ny < c) {
			if (!alphabet[((int)map[nx][ny]) - 65]) {
				alphabet[((int)map[nx][ny]) - 65]++;
				dfs(nx, ny, find_path + 1);
				alphabet[((int)map[nx][ny]) - 65]--;

			}
		}
	}
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	alphabet[((int)map[0][0]) - 65]++;
	dfs(0, 0, 1);
	cout << max_path << endl;
	return 0;
}
