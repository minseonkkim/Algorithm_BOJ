#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
bool isFind;
vector<int> v[3001];
bool visited[3001]; 
int prv[3001];
bool isCycle[3001];
int answer[3001];

void findcycle(int node){
	visited[node] = true;
	for(int i = 0; i < v[node].size(); i++){
		if(isFind) return;
		int next = v[node][i];
		if(visited[next]){
			if(next != prv[node]){
				isCycle[node] = true;
				while(node != next){
					isCycle[prv[node]] = true;
					node = prv[node];
				}
				isFind = true;
				return;
			}
		} else{
			prv[next] = node;
			findcycle(next);
		}
	}
}

void bfs(){
	queue<pair<int, int>> q;
	for(int i = 1; i <= N; i++){
		if(isCycle[i]){
			visited[i] = true;
			q.push({i, 0});
		}
	}
	while(!q.empty()){
		int cur = q.front().first;
		int dis = q.front().second;
		q.pop();
		visited[cur] = true;
		
		for(int i = 0; i < v[cur].size(); i++){
			int next = v[cur][i];
			int ndis = dis + 1;
			if(visited[next]) continue;
			answer[next] = ndis;
			q.push({next, ndis});
		}
	}
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	findcycle(1);
	memset(visited, false, sizeof(visited));
	bfs();
	for(int i = 1; i <= N; i++) cout << answer[i] << " ";
	return 0;
}
