#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char univ[1001];
int parent[1001];

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
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		cin >> univ[i];
	
	for(int i = 1; i <= n; i++)
		parent[i] = i;
		
	vector<pair<int, pair<int, int>>> v;
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(univ[a] != univ[b]){
			v.push_back({c, {a, b}});
		}
	}
	sort(v.begin(), v.end());
	
	int ans = 0, cnt = 0;
	for(int i = 0; i < v.size(); i++){
		if(!findParent(v[i].second.first, v[i].second.second)){
			ans += v[i].first;
			unionParent(v[i].second.first, v[i].second.second);
			cnt++;
		}
	}
	if(cnt < n - 1) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
