#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define MAX 21
#define INF 987654321
using namespace std;

int d[MAX];
int pv[MAX];
vector<pair<int, int>> v[MAX];
stack<int> st;

void dijkstra(){
	d[0] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.push({0, 0});
	
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
	
	int t;
	cin >> t;
	
	for(int k = 0; k < t; k++){
		int n, m;
		cin >> n >> m;
		
		for(int i = 0; i < MAX; i++){
			d[i] = INF;
			v[i].clear();
			pv[i] = -1;
		}
		
		for(int i = 0; i < n; i++){
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({c, b});
			v[b].push_back({c, a});
		}
		
		dijkstra();
		
		cout << "Case #" << k + 1 << ": ";
		if(d[m - 1] == INF) cout << -1;
		else{
			for(int i = m - 1; i > 0; )
				st.push(i = pv[i]);
			while(!st.empty()){
				cout << st.top() << " ";
				st.pop();
			}
			cout << m - 1;
		}
		cout << endl;
	}
	return 0;
}
