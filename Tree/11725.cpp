#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int parent[100001];
bool visited[100001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n;
	cin >> n;
	vector<int> node[100001];
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
		int cur = q.front();
		q.pop();
		for(int i = 0; i < node[cur].size(); i++){
			int next = node[cur][i];
			if(!visited[next]){
				parent[next] = cur;
				visited[next] = true;
				q.push(next);
			}
		}
	}
 
	for(int i = 2; i <= n; i++){
		cout << parent[i] << '\n';
	}
	return 0;
}
