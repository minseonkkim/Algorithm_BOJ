#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
int map[1000][1000];
int group[1000][1000];
int answer[1000][1000];
bool visited[1000][1000];
vector<int> group_size;
int group_num = 1;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    group[x][y] = group_num;
    int cnt = 1;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (!visited[nx][ny] && map[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
                group[nx][ny] = group_num;
                cnt++;
            }

        }
    }
    group_num++;
    group_size.push_back(cnt);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j] - '0';
        }
    }
    group_size.push_back(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                set<int> group_nums;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (map[nx][ny] == 0) {
                        group_nums.insert(group[nx][ny]);
                    }
                }
                int sum = 1;
                for (int n : group_nums) {
                    sum += group_size[n];
                }
                answer[i][j] = sum % 10;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << answer[i][j];
        }
        cout << endl;
    }
}
