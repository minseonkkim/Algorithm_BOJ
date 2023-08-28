#include <iostream>
using namespace std;

int n, m;
int map[9][9];
int map2[9][9];
int x1, y1, x2, y2, x3, y3;
int num, ans;
int virus[64][2];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void dfs(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx > n || ny > m || nx <= 0 || ny <= 0 || map2[nx][ny]) continue;
		
		map2[nx][ny] = 2;
		dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> map[i][j];
			map2[i][j] = map[i][j];
			if(map[i][j] == 2){
				virus[num][0] = i;
				virus[num][1] = j;
				num++;
			}
		}
	}
	
	for(int i = 0; i < n * m; i++){
		x1 = i / m + 1;  y1 = i % m + 1;
		if(!map2[x1][y1]){
			for(int j = i + 1; j < n * m; j++){
				x2 = j / m + 1;  y2 = j % m + 1;
				if(!map2[x2][y2]){
					for(int k = j + 1; k < n * m; k++){
						x3 = k / m + 1; y3 = k % m + 1;
						if(!map2[x3][y3]){
							map2[x1][y1] = 1;
							map2[x2][y2] = 1;
							map2[x3][y3] = 1;
							
							for(int p = 0; p < num; p++)
								dfs(virus[p][0], virus[p][1]);
								
							int cnt = 0;
							for(int p = 1; p <= n; p++){
								for(int q = 1; q <= m; q++){
									if(!map2[p][q]) cnt++;
									map2[p][q] = map[p][q];  //초기화
 								}
							}
							if(cnt > ans) ans = cnt;
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
