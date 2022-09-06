#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int n, m;
vector<int> v[MAX];
int cpm[MAX];

void dfs(int num){
	for(int i = 0; i < v[num].size(); i++){
		cpm[v[num][i]] += cpm[num];
		dfs(v[num][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x != -1){
			v[x].push_back(i);
		}
	}
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		cpm[a] += b;
	}
	
	dfs(1);
	
	for(int i = 1; i <= n; i++){
		cout << cpm[i] << " ";
	}
	return 0;
}
