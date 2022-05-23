#include <iostream>
using namespace std;

int n, m;
int parent[500001];

int getParent(int a){
	if(a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
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
		if(findParent(a, b)) {
			cout << i + 1 << endl;
			return 0;
		}
		unionParent(a, b);
	}
	cout << 0 << endl;
	return 0;
}
