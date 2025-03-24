#include <iostream>
#include <queue>
using namespace std;

int n, m;
char a[50][50];
char b[50][50];
bool visited[50][50];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(int x, int y){
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[x][y] = true;
	
	int acolor = a[x][y];
	int bcolor = b[x][y];
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		a[cx][cy] = bcolor;
		
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(visited[nx][ny] || a[nx][ny] != acolor) continue;
			
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			a[i][j] = s[j];
		}
	}
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			b[i][j] = s[j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j] && a[i][j] != b[i][j]){
				bfs(i, j);
			}
		}
	}
	
	bool same = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != b[i][j]){
				same = false;
				break;
			}
		}
		if(!same) break;
	}
	
	if(same) cout << "YES";
	else cout << "NO";
	return 0;
}
