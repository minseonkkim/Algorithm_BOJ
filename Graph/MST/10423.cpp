#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int parent[1001];
int ans;

int getParent(int x){
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a > b) parent[a] = b;
	else parent[b] = a;
}

bool findParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a == b) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) parent[i] = i;
	for(int i = 1; i <= k; i++){
		int x;
		cin >> x;
		parent[x] = -1;
	}
	
	vector<pair<int, pair<int, int>>> vt;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		vt.push_back({w, {u, v}});
	}
	sort(vt.begin(), vt.end());
	
	for(int i = 0; i < m; i++){
		if(!findParent(vt[i].second.first, vt[i].second.second)){
			ans += vt[i].first;
			unionParent(vt[i].second.first, vt[i].second.second);
		}
	}
	cout << ans << endl;
	return 0;
}
