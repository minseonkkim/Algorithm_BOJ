#include <iostream>
using namespace std;

int map[50][50];
bool visited[50][50];

int n, m, x, y, d; // d : 0 - 북 / 1 - 동 / 2 - 남 / 3 - 서
int answer = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(){  
    for(int i = 0; i < 4; i++){
        int nd = (d + 3 - i) % 4;
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(map[nx][ny] == 1) continue;

        if(map[nx][ny] == 0 && !visited[nx][ny]){
            visited[nx][ny] = true;
            x = nx; y = ny; d = nd;
            answer++;
            dfs();
        }
    }

    // 후진
    int back_d = (d + 2) % 4;
    int nx = x + dx[back_d];
    int ny = y + dy[back_d];

    if(nx < 0 || ny < 0 || nx > n || ny > m) return;

    if(map[nx][ny] == 1){  // 후진 못하면 작동 멈춤
        return;
    } else{
        x = nx;
        y = ny;
        dfs();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x >> y >> d;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    
    visited[x][y] = true;
    answer++;

    dfs();
    cout << answer;
    return 0;
}
