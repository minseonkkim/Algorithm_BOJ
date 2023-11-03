#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, t, m, l;
vector<pair<int, pair<int, int>>> street[101];
bool visited[101];

bool canGo = false;
int min_fee_sum = 987654321;

void dfs(int x, int time_sum, int fee_sum){
	visited[x] = true;
	
	if(x == n){
		canGo = true;
		min_fee_sum = min(min_fee_sum, fee_sum);
		return;
	}
	
	for(int i = 0; i < street[x].size(); i++){
		int nx = street[x][i].first;
		int tt = street[x][i].second.first;
		int ff = street[x][i].second.second;
		
		if(visited[nx]) continue;
		if(time_sum + tt <= t && fee_sum + ff <= m){
			visited[nx] = true;
			dfs(nx, time_sum + tt, fee_sum + ff);
			visited[nx] = false;
		}
	}
}

int main() {
	cin >> n >> t >> m >> l;
	for(int i = 0; i < l; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		street[a].push_back({b, {c, d}});
		street[b].push_back({a, {c, d}});
	}
	
	dfs(1, 0, 0);
	
	if(!canGo) cout << -1;
	else cout << min_fee_sum;
	return 0;
}
