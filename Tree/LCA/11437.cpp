#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[50001];
int depth[50001];
bool visited[50001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> node[50001];
	for(int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}
	
	queue<int> q;
	q.push(1);
	visited[1] = true;
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		for(int i = 0; i < node[x].size(); i++){
			if(!visited[node[x][i]]){
				depth[node[x][i]] = depth[x] + 1;
				visited[node[x][i]] = true;
				parent[node[x][i]] = x;
				q.push(node[x][i]);
			}
		}
	}

	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
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
		cout << x << '\n';
	}
	return 0;
}
