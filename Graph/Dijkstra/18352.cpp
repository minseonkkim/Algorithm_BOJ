#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 300001
#define MAX_EDGE 1000001
using namespace std;

int d[MAX];
vector<int> v[MAX_EDGE];

void dijkstra(int start){
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	
	while(!pq.empty()){
		int cur = pq.top().second;
		int start_to_cur_dis = -pq.top().first;
		pq.pop();
		
		if(d[cur] < start_to_cur_dis) continue;
		
		for(int i = 0; i < v[cur].size(); i++){
			int next = v[cur][i];
			int start_to_next_dis = d[cur] + 1;
			
			if(start_to_next_dis < d[next]){
				d[next] = start_to_next_dis;
				pq.push({-start_to_next_dis, next});
			}
		}
	}
}

int main() {
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	
	for(int i = 1; i <= n; i++)
		d[i] = INF;
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	
	dijkstra(x);
	
	bool t = false;
	for(int i = 1; i <= n; i++){
		if(d[i] == k){
			cout << i << endl;
			t = true;
		}
	}
	if(!t) cout << -1 << endl;
	return 0;
}
