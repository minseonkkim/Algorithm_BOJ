#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int maxlength = -1, answer;
int map[50][50];
bool visited[50][50];

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

pair<int, int> bfs(int x, int y) {
	int sum = map[x][y];  // 비밀번호
	int num;  // 마지막 숫자
	int maxlen = 1;  // 최대 길이

	queue<pair<pair<int, int>, int>> q;
	q.push({ { x, y }, 1 });
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int clen = q.front().second;
		if (clen > maxlen) {
			maxlen = clen;
			num = map[cx][cy];
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (!visited[nx][ny] && map[nx][ny] != 0) {
				visited[nx][ny] = true;
				q.push({ { nx, ny }, clen + 1 });
			}
		}
	}
	sum += num;
	return {maxlen, sum};
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0) {
				init();
				pair<int, int> p = bfs(i, j);
				int len = p.first;
				int pw = p.second;
				if (len > maxlength) {
					maxlength = len;
					answer = pw;
				}
				else if (len == maxlength && pw > answer) {
					maxlength = len;
					answer = pw;
				}
			}
		}
	}
	cout << answer;
}
