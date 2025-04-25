#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int n, m;
int ans_num, ans_dis, ans_cnt;
vector<int> edge[20001];
bool visited[20001];
 
void bfs(){
	queue<pair<int, int>> q;
	q.push({1, 0});
	visited[1] = true;
 
	while(!q.empty()){
		int cur = q.front().first;
		int dis = q.front().second;
		q.pop();
		if(dis > ans_dis){
			ans_num = cur;
			ans_dis = dis;
			ans_cnt = 1;
		} else if(dis == ans_dis){
			ans_cnt++;
			if(cur < ans_num) ans_num = cur;
		}
 
		for(int i = 0; i < edge[cur].size(); i++){
			int next = edge[cur][i];
			int ndis = dis + 1;
 
			if(!visited[next]){
				visited[next] = true;
				q.push({next, ndis});
			}
		}
	}
}
 
int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	bfs();
	cout << ans_num << " " << ans_dis << " " << ans_cnt;
	return 0;
}
