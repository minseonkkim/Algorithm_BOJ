#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool visited[100001];

int bfs(){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	visited[n] = true;
	q.push({0, n});
	
	while(!q.empty()){
		int t = q.top().first;
		int c = q.top().second;
		q.pop();

		if(c == k) return t;
		
		if(c * 2 <= 100000 && !visited[c * 2]){
			q.push({t, c * 2});
			visited[c * 2] = true;
		}
		if(c + 1 <= 100000 && !visited[c + 1]){
			q.push({t + 1, c + 1});
			visited[c + 1] = true;
		}
		if(c - 1 >= 0 && !visited[c - 1]){
			q.push({t + 1, c - 1});
			visited[c - 1] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	cout << bfs() << endl;
	return 0;
}
