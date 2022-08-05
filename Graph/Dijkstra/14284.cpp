#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 5001
#define MAX_EDGE 100001
using namespace std;

int d[MAX];
vector<pair<int, int>> v[MAX_EDGE];

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
			int next = v[cur][i].second;
			int start_to_next_dis = d[cur] + v[cur][i].first;
			
			if(start_to_next_dis < d[next]){
				d[next] = start_to_next_dis;
				pq.push({-start_to_next_dis, next});
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		d[i] = INF;
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({c, b});
		v[b].push_back({c, a});
	}
	
	int s, t;
	cin >> s >> t;
	
	dijkstra(s);
	
	cout << d[t] << endl;
	return 0;
}
