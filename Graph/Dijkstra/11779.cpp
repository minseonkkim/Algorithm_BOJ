#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define MAX_EDGE 1001
#define MAX 100001
#define INF 987654321
using namespace std;

int d[MAX];
int pv[MAX];
vector<pair<int, int>> v[MAX_EDGE];
stack<int> st;

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
			
			if(start_to_next_dis < d[next]){
				d[next] = start_to_next_dis;
				pv[next] = cur;
				pq.push({-start_to_next_dis, next});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i <= n; i++){
		d[i] = INF;
	}
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({c, b});
	}
	
	int start, end;
	cin >> start >> end;
	dijkstra(start);
	
	cout << d[end] << endl;
	for(int i = end; i > 0;){
		if(i == start) break;
		st.push(i = pv[i]);
	}
	cout << st.size() + 1 << endl;
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	cout << end;
	return 0;
}
