#include <iostream>
using namespace std;

int n;
int parent[300001];

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
	
	for(int i = 1; i < n; i++)
		parent[i] = i;
	
	for(int i = 0; i < n - 2; i++){
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			if(!findParent(i, j)){
				cout << i << " " << j;
				return 0;
			}
		}
	}
}
