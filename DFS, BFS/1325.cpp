#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> rel[10001];
bool visited[10001];

int bfs(int start){
	for(int i = 1; i <= n; i++) 
		visited[i] = false;
	queue<int> q;
	q.push(start);
	visited[start] = true;
	
	int cnt = 1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 0; i < rel[cur].size(); i++){
			int next = rel[cur][i];
			if(!visited[next]){
				visited[next] = true;
				q.push(next);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		rel[b].push_back(a);
	}
	int hackcnt[10001];
	int maxcnt = 0;
	for(int i = 1; i <= n; i++){
		hackcnt[i] = bfs(i);
		if(hackcnt[i] > maxcnt) maxcnt = hackcnt[i];
	}
	for(int i = 1; i <= n; i++){
		if(hackcnt[i] == maxcnt) cout << i << " ";
	}
	
	return 0;
}
