#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int f, s, g, u, d;
bool visited[1000001];

int main() {
	cin >> f >> s >> g >> u >> d;
	
	queue<pair<int, int>> q;
	q.push({s, 0});
	visited[s] = true;
	
	int answer = 987654321;
	
	while(!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(cur == g){
			answer = min(answer, cnt);
			break;
		}
		
		int ups = cur + u;
		if(ups <= f && !visited[ups]){
			q.push({ups, cnt + 1});
			visited[ups] = true;
		}
		
		int downs = cur - d;
		if(downs >= 1 && !visited[downs]){
			q.push({downs, cnt + 1});
			visited[downs] = true;
		}
	}
	if(answer == 987654321) cout << "use the stairs";
	else cout << answer;
	return 0;
}
