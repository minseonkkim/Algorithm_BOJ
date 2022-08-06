#include <iostream>
#include <vector>
#include <queue>
#define INF 2e9
#define MAX 100001
#define MAX_EDGE 200001
using namespace std;

int n, m, x, y, z;
int d[MAX];
vector<pair<int, int>> v[MAX_EDGE];

void dijkstra(int start){
	for(int i = 0; i <= n; i++)
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
			int start_to_next_dis = start_to_cur_dis + v[cur][i].first;
			
			if(d[next] > start_to_next_dis){
				d[next] = start_to_next_dis;
				pq.push({-start_to_next_dis, next});
			}
		}
	}
}

void dijkstra2(int start){
	for(int i = 0; i <= n; i++)
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
			int start_to_next_dis = start_to_cur_dis + v[cur][i].first;
			
			if(next == y) continue;
			
			if(d[next] > start_to_next_dis){
				d[next] = start_to_next_dis;
				pq.push({-start_to_next_dis, next});
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({c, b});
	}
	
	cin >> x >> y >> z;
	
	dijkstra(x);
	int t = d[y];
	dijkstra(y);
	if(t == INF || d[z] == INF) cout << -1 << " ";
	else cout << t + d[z] << " ";

	dijkstra2(x);
	if(d[z] == INF) cout << -1 << endl;
	else cout << d[z] << endl;
	return 0;
}
