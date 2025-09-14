#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];

int getParent(int x){
	if(x == parent[x]) return x;
	else return parent[x] = getParent(parent[x]);
}

bool findParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a == b) return true;
	else return false;
}

void unionParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a > b) parent[a] = b;
	else parent[b] = a;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i <= n; i++) parent[i] = i;
	vector<pair<int, pair<int, int>>> v; 
	int mincnt = 0, maxcnt = 0;
	int a, b, c;
	for(int i = 0; i < m + 1; i++){
		cin >> a >> b >> c;
		if(c == 0) v.push_back({1, {a, b}});
		else v.push_back({0, {a, b}});
	}
	sort(v.begin(), v.end(), greater<>());
	for(int i = 0; i < v.size(); i++){
		if(!findParent(v[i].second.first, v[i].second.second)){
			unionParent(v[i].second.first, v[i].second.second);
			if(v[i].first == 1) maxcnt++;
		}
	}
	
	for(int i = 0; i <= n; i++) parent[i] = i;
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++){
		if(!findParent(v[i].second.first, v[i].second.second)){
			unionParent(v[i].second.first, v[i].second.second);
			if(v[i].first == 1) mincnt++;
		}
	}
	cout << maxcnt * maxcnt - mincnt * mincnt;
	return 0;
}
