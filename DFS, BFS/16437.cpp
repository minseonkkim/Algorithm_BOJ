#include <iostream>
#include <vector>
using namespace std;

int n;
long long island[123457];
vector<int> tree[123457];

long long dfs(int now){
	if(tree[now].empty()){
		if(island[now] > 0) return island[now];
		else return 0;
	}
	
	long long sum = 0;
	sum += island[now];
	
	for(int i = 0; i < tree[now].size(); i++){
		sum += dfs(tree[now][i]);
	}
	
	if(sum < 0) return 0;
	else return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 2; i <= n; i++){
		char t; long long a; int p;
		cin >> t >> a >> p;
		if(t == 'S'){
			island[i] = a;
		} else if(t == 'W'){
			island[i] = -a;
		}
		tree[p].push_back(i);
	}
	cout << dfs(1) << endl;
	return 0;
}
