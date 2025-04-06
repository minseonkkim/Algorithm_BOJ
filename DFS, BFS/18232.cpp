#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, s, e;
vector<int> edge[300001];
bool visited[300001];

void bfs(){
	queue<pair<int, int>> q;
	q.push({s, 0});
	visited[s] = true;
	
	while(!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(cur == e){
			cout << cnt;
			return;
		}
		
		int next = cur + 1;
		if(next <= n && !visited[next]){
			visited[next] = true;
			q.push({next, cnt + 1});
		}
		
		next = cur - 1;
		if(next >= 1 && !visited[next]){
			visited[next] = true;
			q.push({next, cnt + 1});
		}
		
		for(int i = 0; i < edge[cur].size(); i++){
			next = edge[cur][i];
			if(!visited[next]){
				visited[next] = true;
				q.push({next, cnt + 1});
			}
		}
	}
}

int main() {
	cin >> n >> m >> s >> e;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	bfs();
	return 0;
}
