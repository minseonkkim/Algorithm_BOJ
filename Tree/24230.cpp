#include <iostream>
#include <vector>
using namespace std;

int n, answer;
int color[200001];
vector<int> edge[200001];

void dfs(int now, int prev){
	for(int i = 0; i < edge[now].size(); i++){
		int next = edge[now][i];
		if(next == prev) continue;
		if(color[now] != color[next]) answer++;
		dfs(next, now);
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> color[i];
	}
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	if(color[1] != 0) answer++;
	dfs(1, 0);
	cout << answer;
	return 0;
}
