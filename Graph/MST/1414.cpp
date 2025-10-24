#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, pair<int, int>>> v;
int parent[51];

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
	cin >> N;
	for(int i = 1; i <= N; i++) parent[i] = i;
	int total = 0;
	for(int i = 1; i <= N; i++){
		string s;
		cin >> s;
		for(int j = 1; j <= N; j++){
			if(s[j - 1] == '0') continue;
			int len = 0;
			if(s[j - 1] >= 'a' && s[j] <= 'z') len = s[j - 1] - 'a' + 1;
			else len = s[j - 1] - 'A' + 27;
			v.push_back({len, {i, j}});
			total += len;
		}
	}
	sort(v.begin(), v.end());
	int conn = 0, cnt = 0;
	for(int i = 0; i < v.size(); i++){
		if(!findParent(v[i].second.first, v[i].second.second)){
			unionParent(v[i].second.first, v[i].second.second);
			conn += v[i].first;
			cnt++;
		}
	}
	if(cnt != N - 1) cout << -1;
	else cout << total - conn;
	return 0;
}
