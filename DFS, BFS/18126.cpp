#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, long long>> edge[5001];
bool visited[5001];
long long answer = 0;

void bfs(){
	queue<pair<int, long long>> q;
	q.push({1, 0});
	visited[1] = true;
	
	while(!q.empty()){
		int cur = q.front().first;
		long long dis = q.front().second;
		q.pop();
		
		if(dis > answer){
			answer = dis;
		}
		
		for(int i = 0; i < edge[cur].size(); i++){
			int next = edge[cur][i].first;
			long long ndis = dis + edge[cur][i].second;
			
			if(!visited[next]){
				visited[next] = true;
				q.push({next, ndis});
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		long long c;
		cin >> a >> b >> c;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}
	bfs();
	cout << answer;
	return 0;
}
