#include <iostream>
#include <queue>
using namespace std;

char map[101][101];
int check[101][101];
bool visit[101][101];
int n, m;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void bfs() {
    visit[0][0] = true;
    
    int cx, cy, ax, ay;
    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    while (!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            ax = cx + dx[i];
            ay = cy + dy[i];

            if (ax >= 0 && ay >= 0 && ax < n && ay < m && visit[ax][ay] == false && map[ax][ay] == '1') {
                visit[ax][ay] = true;
                check[ax][ay] = check[cx][cy] + 1;
                q.push(pair<int, int>(ax, ay));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    bfs();
    cout << check[n - 1][m - 1] + 1 << endl;

    return 0;
}
