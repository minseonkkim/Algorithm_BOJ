#include<iostream>
#include<queue>
using namespace std;
 
int arr[52][52];
int n, m;
int maximum=0;
int ans = 0;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
 
void bfs(int h) {
    arr[0][0] = h;
    queue <pair<int, int>> q;
    q.push({ 0,0 });
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
 
        int ny, nx;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (!(ny >= 0 && ny <= n + 1 && nx >= 0 && nx <= m + 1)) continue;
            if (arr[ny][nx] < h) {
                arr[ny][nx] = h;
                q.push({ ny,nx });
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
            if (arr[i][j] > maximum) maximum = arr[i][j];
        }
    }
 
    for (int o = 1; o <= maximum; o++) {
        bfs(o);
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] < o) {
                    ans += 1;
                    arr[i][j] += 1;
                }
            }
        }
    }
 
    cout << ans << endl;
    return 0;
}
