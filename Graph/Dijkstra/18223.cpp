#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_VERTEX 5001
#define MAX_EDGE 10001
using namespace std;

int v, e, p;
int d[MAX_VERTEX];
vector<pair<int, int>> edge[MAX_EDGE];

void dijkstra(int start){
	for(int i = 1; i <= v; i++) d[i] = INF;
	
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	
	while(!pq.empty()){
		int cur = pq.top().second;
		int start_to_cur_dis = -pq.top().first;
		pq.pop();
		
		if(d[cur] < start_to_cur_dis) continue;
		
		for(int i = 0; i < edge[cur].size(); i++){
			int next = edge[cur][i].second;
			int start_to_next_dis = start_to_cur_dis + edge[cur][i].first;
			
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
	
	cin >> v >> e >> p;
	for(int i = 0; i < e; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({c, b});
		edge[b].push_back({c, a});
	}
	
	dijkstra(1);
	int t1 = d[v];
	int t2 = d[p];
	dijkstra(p);
	if(t1 == t2 + d[v]) cout << "SAVE HIM" << endl;
	else cout << "GOOD BYE" << endl;
	
	return 0;
}
