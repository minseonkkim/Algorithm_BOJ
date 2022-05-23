#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[100001];

int getParent(int a){
	if(a == parent[a]) return a;
	return getParent(parent[a]);
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
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	vector<pair<int, pair<int, int>>> v;
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({c, {a, b}});
	}
	sort(v.begin(), v.end());
	
	for(int i = 1; i <= n; i++)
		parent[i] = i;
	
	int maxcost = 0;
	int result = 0;
	for(int i = 0; i < m; i++){
		if(!findParent(v[i].second.first, v[i].second.second)){
			unionParent(v[i].second.first, v[i].second.second);
			result += v[i].first;
			maxcost = max(maxcost, v[i].first);
		}
	}
	cout << result - maxcost << endl;
	return 0;
}
