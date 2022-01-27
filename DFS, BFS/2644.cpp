#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[101][101];
int visit[101];
int depth[101];

void bfs(int start){
	visit[start] = 1;
	
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		visit[node] = 1;
		
		for(int i = 1; i <= n; i++){
			if(!visit[i] && map[node][i] == 1){
				q.push(i);
				visit[i] = 1;
				depth[i] = depth[node] + 1;
			}
		}
	}
}

int main() {
	int a, b, x, y;
	cin >> n;
	cin >> a >> b;
	
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}
	
	bfs(a);
	
	if(depth[b] == 0) cout << -1 << endl;
	else cout << depth[b] << endl;
	
	return 0;
}
