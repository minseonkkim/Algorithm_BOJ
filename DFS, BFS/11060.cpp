#include <iostream>
#include <queue>
using namespace std;

int n;
int map[1001];
bool visited[1001];

void bfs(){
	queue<pair<int, int>> q;
	q.push({1, 0});
	visited[1] = true;
	
	while(!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(cur == n){
			cout << cnt;
			return;
		}
		
		for(int i = 0; i <= map[cur]; i++){
			int next = cur + i;
			
			if(next > n || visited[next]) continue;
			
			visited[next] = true;
			q.push({next, cnt + 1});
		}
	}
	cout << -1;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> map[i];
	}
	bfs();
	return 0;
}
