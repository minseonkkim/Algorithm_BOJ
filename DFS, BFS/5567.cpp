#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v[501];
bool visited[501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	int ans = 0;
	queue<int> q;
	q.push(1);
	visited[1] = true;
	
	for(int i = 0; i < v[1].size(); i++){
		q.push(v[1][i]);
		visited[v[1][i]] = true;
		ans++;
	}
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		for(int i = 0; i < v[cur].size(); i++){
			int next = v[cur][i];
			if(visited[next]) continue;
			visited[next] = true;
			ans++;
 		}
	}
	cout << ans << endl;
	return 0;
}
