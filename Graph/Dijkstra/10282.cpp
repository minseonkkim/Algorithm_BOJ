#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
#define INF 987654321
using namespace std;

vector<pair<int, int>> v[MAX];
int d[MAX];

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
			int start_to_next_dis = start_to_cur_dis + v[cur][i].first;
			
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
	
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		int n, q, c;
		cin >> n >> q >> c;
		
		for(int i = 0; i <= n; i++){
			d[i] = INF;
			v[i].clear();
		}
		
		for(int i = 0; i < q; i++){
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back({s, a});
		}
		
		dijkstra(c);
		
		int cnt = 0, max = 0;
		for(int i = 1; i <= n; i++){
			if(d[i] != INF){
				cnt++;
				if(d[i] > max) max = d[i];
			}
		}
		
		cout << cnt << " " << max << endl;
	}
	
	return 0;
}
