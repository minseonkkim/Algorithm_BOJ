#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 801
#define INF 987654321
using namespace std;

vector<pair<int, int>> v[MAX];
int d[MAX];
int n, e;
int v1, v2;

void dijkstra(int start){
	for(int i = 0; i <= n; i++) d[i] = INF;
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	
	while(!pq.empty()){
		int cur = pq.top().second;
		int start_to_cur_dis = -pq.top().first;
		pq.pop();
		
		if(d[cur] < start_to_cur_dis) continue;
		
		for(int i = 0; i < v[cur].size(); i++){
			int next = v[cur][i].first;
			int start_to_next_dis = start_to_cur_dis + v[cur][i].second;
			
			if(d[next] > start_to_next_dis){
				d[next] = start_to_next_dis;
				pq.push({-start_to_next_dis, next});
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    dijkstra(1);
    int onetov1 = d[v1];
    int onetov2 = d[v2];
    
    dijkstra(v1);
    int v1tov2 = d[v2];
    int v1ton = d[n];
    
    dijkstra(v2);
    int v2ton = d[n];
    
    int res = INF;
    res = min(res, onetov1 + v1tov2 + v2ton);
    res = min(res, onetov2 + v1tov2 + v1ton);
    
    if(v1tov2 == INF || res == INF) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}
