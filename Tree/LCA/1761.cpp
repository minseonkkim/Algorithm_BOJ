#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int parent[40001];
int depth[40001];
int length[40001];
bool visited[40001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n;
	cin >> n;
	vector<pair<int, int>> node[40001];
	for(int i = 0; i < n - 1; i++){
		int x, y, dis;
		cin >> x >> y >> dis;
		node[x].push_back({y, dis});
		node[y].push_back({x, dis});
	}
 
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 0; i < node[cur].size(); i++){
			int next = node[cur][i].first;
			int len = node[cur][i].second;
			if(!visited[next]){
				depth[next] = depth[cur] + 1;
				parent[next] = cur;
				length[next] = length[cur] + len;
				visited[next] = true;
				q.push(next);
			}
		}
	}
 
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		int a = length[x];
		int b = length[y];
		if(depth[x] > depth[y]){
			int tmp = x;
			x = y;
			y = tmp;
		}
		while(depth[x] != depth[y]){
			y = parent[y];
		}
		while(x != y){
			x = parent[x];
			y = parent[y];
		}
		cout << a + b - 2 * length[x] << '\n';
	}
	return 0;
}
