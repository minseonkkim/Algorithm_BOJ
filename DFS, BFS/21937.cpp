#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x;
vector<int> v[100001];
bool visited[100001];
int answer;

void bfs(){
	queue<int> q;
	q.push(x);
	visited[x] = true;
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		for(int i = 0; i < v[cur].size(); i++){
			int next = v[cur][i];
			if(visited[next]) continue;
			visited[next] = true;
			q.push(next);
			answer++;
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	cin >> x;
	bfs();
	cout << answer;
	return 0;
}
