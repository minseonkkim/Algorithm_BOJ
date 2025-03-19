#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k, answer_time = 987654321, answer_cnt;
bool visited[100001];

void bfs(){
	queue<pair<int, int>> q;
	q.push({n, 0});
	visited[n] = true;
	
	while(!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visited[cur] = true;
		if(cur == k){
			if(cnt < answer_time){
				answer_time = cnt;
				answer_cnt = 1;
			} else if(cnt == answer_time){
				answer_cnt++;
			}
			continue;
		}
		
		int next = cur + 1;
		if(next >= 0 && next <= 100000 && !visited[next]) {
			q.push({next , cnt + 1});
		}
		
		next = cur - 1;
		if(next >= 0 && next <= 100000 && !visited[next]) {
			q.push({next , cnt + 1});
		}
		
		next = cur * 2;
		if(next >= 0 && next <= 100000 && !visited[next]) {
			q.push({next , cnt + 1});
		}
	}
}

int main() {
	cin >> n >> k;
	bfs();
	cout << answer_time << '\n' << answer_cnt;
	return 0;
}
