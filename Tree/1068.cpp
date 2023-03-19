#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[50];
int n, k, root;
int leafcnt = 0;

int dfs(int node){
	if(node == k) return -1;
	if(tree[node].size() == 0){
		leafcnt++;
		return 0;
	}
	for(int i = 0; i < tree[node].size(); i++){
		int tmp = dfs(tree[node][i]);
		if(tmp == -1 && tree[node].size() == 1) leafcnt++;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		if(p == -1) root = i;
		else tree[p].push_back(i);
	}
	cin >> k;
	dfs(root);
	cout << leafcnt;
	return 0;
}
