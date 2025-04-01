#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int s, t;
bool visited[1001][1001];

int bfs(){
	memset(visited, false, sizeof(visited));
	
	queue<pair<pair<int, int>, int>> q;
	q.push({{s, t}, 0});
	visited[s][t] = true;
	
	while(!q.empty()){
		int a = q.front().first.first;
		int o = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		
		if(a == o) return cnt;
		
		int nt = a * 2;
		int no = o + 3;
		if(nt <= 1000 && no <= 1000 && !visited[nt][no]){
			visited[nt][no] = true;
			q.push({{nt, no}, cnt + 1});
		}
		
		nt = a + 1;
		no = o;
		if(nt <= 1000 && no <= 1000 && !visited[nt][no]){
			visited[nt][no] = true;
			q.push({{nt, no}, cnt + 1});
		}
	}
	return -1;
}

int main() {
	int c;
	cin >> c;
	for(int i = 0; i < c; i++){
		cin >> s >> t;
		cout << bfs() << '\n';
	}
	return 0;
}
