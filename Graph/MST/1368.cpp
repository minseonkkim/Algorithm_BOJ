#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int parent[301];
 
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
	int n;
	cin >> n;
	vector<pair<int, pair<int, int>>> v;
	for(int i = 0; i <= n; i++){
		parent[i] = i;
	}
	for(int i = 1; i <= n; i++){
		int w;
		cin >> w;
		v.push_back({w, {0, i}});
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int p;
			cin >> p;
			if(i <= j) continue;
			v.push_back({p, {i, j}});
		}
	}
	sort(v.begin(), v.end());
	int answer = 0;
	for(int i = 0; i < v.size(); i++){
		if(!findParent(v[i].second.first, v[i].second.second)){
			unionParent(v[i].second.first, v[i].second.second);
			answer += v[i].first;
		}
	}
	cout << answer;
	return 0;
}
