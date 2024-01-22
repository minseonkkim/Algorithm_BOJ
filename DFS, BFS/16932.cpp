#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
int arr[1000][1000];
bool visited[1000][1000];
int group[1000][1000];
int group_num = 1;
vector<int> group_size;
int answer = -1;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	group[x][y] = group_num;
	visited[x][y] = true;
	int cnt = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (arr[nx][ny] == 1 && !visited[nx][ny]) {
				group[nx][ny] = group_num;
				visited[nx][ny] = true;
				q.push({ nx, ny });
				cnt++;
			}
		}
	}
	group_size.push_back(cnt);
	group_num++;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	group_size.push_back(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				set<int> group_nums;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (arr[nx][ny] == 1) {
						group_nums.insert(group[nx][ny]);
					}
				}
				int sum = 1;
				for (int n : group_nums) {
					sum += group_size[n];
				}
				if (sum > answer) answer = sum;
			}
		}
	} 

	cout << answer;
	return 0;
}
