#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int N, L, R, X;
vector<int> level;
int answer = 0;

void dfs(int idx, int sum, int mx, int mn, int cnt){
	if(idx == N){
		if(cnt >= 2 && sum >= L && sum <= R && mx - mn >= X) answer++;
		return;
	}
	
	dfs(idx + 1, sum, mx, mn, cnt);
	dfs(idx + 1, sum + level[idx], max(mx, level[idx]), min(mn, level[idx]), cnt + 1);
}

int main() {
	cin >> N >> L >> R >> X;
	for(int i = 0; i < N; i++){
		int tp;
		cin >> tp;
		level.push_back(tp);
	}
	
	dfs(0, 0, INT_MIN, INT_MAX, 0);
	cout << answer;
	return 0;
}
