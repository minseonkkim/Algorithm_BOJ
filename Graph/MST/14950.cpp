#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, t;
int parent[10001];

int getParent(int a){
	if(parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
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
	cin >> N >> M >> t;
	
	vector<pair<int, pair<int, int>>> v;
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({c, {a, b}});
	}
	sort(v.begin(), v.end());
	
	for(int i = 1; i <= N; i++) parent[i] = i;
	
	int answer = 0;
	int cnt = 0;
	for(int i = 0; i < M; i++){
		if(!findParent(v[i].second.first, v[i].second.second)){
			unionParent(v[i].second.first, v[i].second.second);
			answer += v[i].first + t * cnt;
			cnt++;
		}
	}
	cout << answer;
	return 0;
}
