#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

bool visited[10000];

string bfs(int a, int b){
	memset(visited, false, sizeof(visited));
	queue<pair<int, string>> q;
	q.push({a, ""});
	visited[a] = true;
	
	while(!q.empty()){
		int cur = q.front().first;
		string cmd = q.front().second;
		q.pop();
		
		if(cur == b) return cmd;
		
		int next = cur * 2 % 10000;
		if(!visited[next]){
			q.push({next, cmd + 'D'});
			visited[next] = true;
		}
		
		next = cur - 1;
		if(next == -1) next = 9999;
		if(!visited[next]){
			q.push({next, cmd + 'S'});
			visited[next] = true;
		}
	
		next = (cur % 1000) * 10 + (cur / 1000);
		if(!visited[next]){
			q.push({next, cmd + 'L'});
			visited[next] = true;
		}
		
		next = (cur % 10) * 1000 + (cur / 10);
		if(!visited[next]){
			q.push({next, cmd + 'R'});
			visited[next] = true;
		}
	}
	return "";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int a, b;
		cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}
	return 0;
}
