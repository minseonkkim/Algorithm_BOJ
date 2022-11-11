#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int parent[1001];
vector<pair<int, pair<int, int>>> v;

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

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if(i < j) v.push_back({a, {i, j}});
		}
	}
	
	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	long long ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!findParent(v[i].second.first, v[i].second.second)) {
			unionParent(v[i].second.first, v[i].second.second);
			ans += v[i].first;
		}
	}

	cout << ans << endl;

	return 0;
}
