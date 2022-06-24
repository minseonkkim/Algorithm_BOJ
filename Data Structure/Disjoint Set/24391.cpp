#include <iostream>
#include <vector>
using namespace std;

int n, m;
int parent[100001];

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
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		parent[i] = i;
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}
	
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	int cnt = 0;
	for(int i = 0; i < n - 1; i++){
		if(!findParent(v[i], v[i + 1])) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
