#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 1001
#define MAX_EDGE 10001
using namespace std;

int n, m, x;
int d[MAX];
vector<pair<int, int>> v[MAX_EDGE];

void dijkstra(int start){
	for(int i = 1; i <= n; i++)
		d[i] = INF;
		
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> x;
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({c, b});
	}
	
	int tmp[MAX];
	dijkstra(x);
	for(int i = 1; i <= n; i++){
		if(d[i] == INF) tmp[i] = -1;
		else tmp[i] = d[i];
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		dijkstra(i);
		if(d[x] == INF || tmp[i] == -1) continue;
		tmp[i] += d[x];
		if(tmp[i] > ans) ans = tmp[i];
	}
	cout << ans << endl;
	return 0;
}
