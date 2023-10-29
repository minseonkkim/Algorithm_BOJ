#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<pair<int, pair<int, int>>> v;
int cnt;
int exist[6][11];

void dfs(int idx, int sum){
	if(sum > k) return;
	if(sum == k) {
		cnt++;
		return;
	}
	if(idx == n) return;
	
	int day = v[idx].first;
	int start = v[idx].second.first;
	int end = v[idx].second.second;
	
	bool flag = false;
	for(int i = start; i <= end; i++){
		if(exist[day][i]) flag = true;
	}
	
	if(!flag && day != 5){
		for(int i = start; i <= end; i++){
			exist[day][i] = true;
		}
		dfs(idx + 1, sum + end - start + 1);
		for(int i = start; i <= end; i++){
			exist[day][i] = false;
		}
	}
	dfs(idx + 1, sum);
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int w, s, e;
		cin >> w >> s >> e;
		v.push_back({w, {s, e}});
	}
	dfs(0, 0);
	cout << cnt;
	return 0;
}
