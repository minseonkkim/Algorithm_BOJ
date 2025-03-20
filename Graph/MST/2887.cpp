#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> xv;
vector<pair<int, int>> yv;
vector<pair<int, int>> zv;
vector<pair<int, pair<int, int>>> edge;
int parent[100000];

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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i = 0; i < 100000; i++) parent[i] = i;
	for(int i = 0; i < n; i++){
		int x, y, z;
		cin >> x >> y >> z;
		xv.push_back({x, i});
		yv.push_back({y, i});
		zv.push_back({z, i});
	}
	
	sort(xv.begin(), xv.end());
	sort(yv.begin(), yv.end());
	sort(zv.begin(), zv.end());
	
	for(int i = 0; i < n - 1; i++){
		edge.push_back({xv[i + 1].first - xv[i].first, {xv[i + 1].second, xv[i].second}});
		edge.push_back({yv[i + 1].first - yv[i].first, {yv[i + 1].second, yv[i].second}});
		edge.push_back({zv[i + 1].first - zv[i].first, {zv[i + 1].second, zv[i].second}});
	}
	
	sort(edge.begin(), edge.end());
	
	int answer = 0;
	for(int i = 0; i < edge.size(); i++){
		if(!findParent(edge[i].second.first, edge[i].second.second)){
			unionParent(edge[i].second.first, edge[i].second.second);
			answer += edge[i].first;
		}
	}
	cout << answer;
	return 0;
}
