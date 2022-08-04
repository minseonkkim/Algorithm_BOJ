#include <iostream>
#include <vector>
#include <queue>
#define MAX_VERTEX 50001
#define MAX 50001
#define INF 987654321
using namespace std;

int n, m;
int d[MAX_VERTEX];
vector<pair<int, int>> edge[MAX];

void dijkstra(){
	d[1] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.push({0, 1});
	
	while(!pq.empty()){
		int current = pq.top().second;
		int start_to_current_dis = -pq.top().first;
		pq.pop();
		
		if(d[current] < start_to_current_dis) continue;
		
		for(int i = 0; i < edge[current].size(); i++){
			int next = edge[current][i].second;
			
			int start_to_next_dis = start_to_current_dis + edge[current][i].first;
			
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
	
	for(int i = 0; i <= n; i++)
		d[i] = INF;
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({c, b});
		edge[b].push_back({c, a});
	}
	
	dijkstra();
	cout << d[n] << endl;
	
	return 0;
}
