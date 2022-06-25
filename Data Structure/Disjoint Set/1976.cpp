#include <iostream>
#include <vector>
using namespace std;

int n, m;
int parent[201];

int getParent(int x){
	if(parent[x] == x) return x;
	return getParent(parent[x]);
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
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		parent[i] = i;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin >> x;
			if(x == 1) unionParent(i, j);
		}
	}
	
	vector<int> v;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	for(int i = 0; i < m - 1; i++){
		if(!findParent(v[i], v[i + 1])){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
