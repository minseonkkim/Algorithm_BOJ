#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct bead{
	int rx, ry;
	int bx, by;
	int cnt;
	string log;
};

int n, m;
char map[10][10];
bool visited[10][10][10][10];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char dc[4] = {'U', 'L', 'R', 'D'};

void bfs(int srx, int sry, int sbx, int sby){
	queue<bead> q;
	q.push({srx, sry, sbx, sby, 0, ""});
	visited[srx][sry][sbx][sby] = true;
	
	while(!q.empty()){
		int crx = q.front().rx;
		int cry = q.front().ry;
		int cbx = q.front().bx;
		int cby = q.front().by;
		int cnt = q.front().cnt;
		string log = q.front().log;
		q.pop();
		
		if(cnt >= 10) break;
		
		for(int i = 0; i < 4; i++){
			int nrx = crx, nry = cry, nbx = cbx, nby = cby;
			string nlog = log + dc[i];
			int rcnt = 0, bcnt = 0;
			while(map[nrx + dx[i]][nry + dy[i]] != '#' && map[nrx][nry] != 'O'){
				nrx += dx[i];
				nry += dy[i];
				rcnt++;
			}
			while(map[nbx + dx[i]][nby + dy[i]] != '#' && map[nbx][nby] != 'O'){
				nbx += dx[i];
				nby += dy[i];
				bcnt++;
			}
			
			if(map[nbx][nby] == 'O') continue;
			if(map[nrx][nry] == 'O'){
				cout << cnt + 1 << '\n';
				cout << nlog;
				return;
			}
			
			if(nrx == nbx && nry == nby){
				if(rcnt > bcnt){
					nrx -= dx[i];
					nry -= dy[i];
				} else{
					nbx -= dx[i];
					nby -= dy[i];
				}
			}
			
			if(visited[nrx][nry][nbx][nby]) continue;
			visited[nrx][nry][nbx][nby] = true;
			q.push({nrx, nry, nbx, nby, cnt + 1, nlog});
		}
	}
	
	cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	int srx, sry, sbx, sby;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			map[i][j] = s[j];
			if(map[i][j] == 'R'){
				srx = i;
				sry = j;
			} else if(map[i][j] == 'B'){
				sbx = i;
				sby = j;
			}
		}
	}
	bfs(srx, sry, sbx, sby);
	return 0;
}
