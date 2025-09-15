#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[201];

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
	for(int i = 1; i <= n; i++) parent[i] = i;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin >> x;
			if(i <= j) continue;
			v.push_back({x, {i, j}});
		}
	}
	sort(v.begin(), v.end());
	int sum = 0, cnt = 0;
	vector<pair<int, int>> newt;
	for(int i = 0; i < v.size(); i++){
		if(v[i].first < 0){
			unionParent(v[i].second.first, v[i].second.second);
			sum += (-v[i].first);
		} else{
			if(!findParent(v[i].second.first, v[i].second.second)){
				unionParent(v[i].second.first, v[i].second.second);
				sum += v[i].first;
				cnt++;
				newt.push_back({v[i].second.first, v[i].second.second});
			}
		}
	}
	cout << sum << " " << cnt << '\n';
	for(int i = 0; i < newt.size(); i++){
		cout << newt[i].first << " " << newt[i].second << '\n';
	}
	return 0;
}
