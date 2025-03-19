#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int m, n;
int parent[200000];
 
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
	return false;
}
 
int main() {
	while(true){
		cin >> m >> n;
		if(m == 0 && n == 0) break;
 
		for(int i = 0; i < m; i++) parent[i] = i;
 
		int origsum = 0;
		vector<pair<int, pair<int, int>>> v;
		for(int i = 0; i < n; i++){
			int x, y, z;
			cin >> x >> y >> z;
			v.push_back({z, {x, y}});
			origsum += z;
		}
		sort(v.begin(), v.end());
 
		int aftersum = 0;
		for(int i = 0; i < n; i++){
			if(!findParent(v[i].second.first, v[i].second.second)){
				unionParent(v[i].second.first, v[i].second.second);
				aftersum += v[i].first;
			}
		}
 
		cout << origsum - aftersum << '\n';
	}
	return 0;
}
