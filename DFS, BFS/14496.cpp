#include <iostream>
#include <queue>
using namespace std;

int a, b, n, m;
vector<int> subs[1001];
bool visited[1001];

void bfs(){
	queue<pair<int, int>> q;
	q.push({a, 0});
	visited[a] = true;
	
	while(!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(cur == b){
			cout << cnt;
			return;
		}
		
		for(int i = 0; i < subs[cur].size(); i++){
			int next = subs[cur][i];
			
			if(!visited[next]){
				visited[next] = true;
				q.push({next, cnt + 1});
			}
		}
	}
	cout << -1;
}

int main() {
	cin >> a >> b >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		subs[x].push_back(y);
		subs[y].push_back(x);
	}
	bfs();
	return 0;
}
