#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int s, answer;
queue<pair<pair<int, int>, int>> q;
bool visited[2001][2001];

void bfs(){
	q.push({{1, 0}, 0});
	visited[1][0] = true;
	
	while(!q.empty()){
		int cur = q.front().first.first;
		int cnt = q.front().first.second;
		int clipboard = q.front().second;
		q.pop();
		
		if(cur == s){
			answer = cnt;
			break;
		}
		
		if(!visited[cur][cur]){
			visited[cur][cur] = true;
			q.push({{cur, cnt + 1}, cur});
		}
		
		
		int next = cur + clipboard;
		if(!visited[next][clipboard] && next <= 2000){
			visited[next][clipboard] = true;
			q.push({{next, cnt + 1}, clipboard});
		}
		
		next = cur - 1;
		if(!visited[next][clipboard] && next >= 1){
			visited[next][clipboard] = true;
			q.push({{next, cnt + 1}, clipboard});
		}
	}
}

int main() {
	cin >> s;
	bfs();
	cout << answer;
	return 0;
}
