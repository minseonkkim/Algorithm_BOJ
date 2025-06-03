#include <iostream>
#include <queue>
using namespace std;

int n, k, s, x, y;
int map[201][201];

struct cmp{
	bool operator()(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b){
		if(a.first.second == b.first.second) return a.first.first > b.first.first;
		else return a.first.second > b.first.second;
	}
};

priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, cmp> pq;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(){
	while(!pq.empty()){
		int type = pq.top().first.first;
		int ct = pq.top().first.second;
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		pq.pop();
		
		if(ct == s) break;
		
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
			if(!map[nx][ny]){
				map[nx][ny] = type;
				pq.push({{type, ct + 1}, {nx, ny}});
			}
			
		}
	}
}

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> map[i][j];
			if(map[i][j]) pq.push({{map[i][j], 0}, {i, j}});
		}
	}
	cin >> s >> x >> y;
	
	bfs();
	cout << map[x][y];
	return 0;
}
