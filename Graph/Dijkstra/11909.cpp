#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, answer = 987654321;
int map[2223][2223];
int dist[2223][2223];

void dijkstra(){
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({0, {1, 1}});
	dist[1][1] = 0;
	
	while(!pq.empty()){
		int cd = -pq.top().first;
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		pq.pop();
		
		if(cx == n && cy == n){
			answer = min(answer, cd);
			continue;
		}
		
		if(dist[cx][cy] < cd) continue;
		
		if(cx != n){
			int nd = cd;
			int nx = cx + 1;
			int ny = cy;
			if(map[cx][cy] <= map[nx][ny]){
				nd += (map[nx][ny] - map[cx][cy] + 1);
			}
			if(dist[nx][ny] > nd){
				dist[nx][ny] = nd;
				pq.push({-nd, {nx, ny}});
			}
		}
		if(cy != n){
			int nd = cd;
			int nx = cx;
			int ny = cy + 1;
			if(map[cx][cy] <= map[nx][ny]){
				nd += (map[nx][ny] - map[cx][cy] + 1);
			}
			if(dist[nx][ny] > nd){
				dist[nx][ny] = nd;
				pq.push({-nd, {nx, ny}});
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> map[i][j];
			dist[i][j] = 987654321;
		}
	}
	dijkstra();
	cout << answer;
	return 0;
}
