#include <iostream>
using namespace std;
 
int parent[100100];
int sum[100100];
 
int getParent(int x){
	if(x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}
 
void unionParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a > b){
		parent[a] = b;
		sum[b] += sum[a];
	} else{
		parent[b] = a;
		sum[a] += sum[b];
	}
}
 
int main() {
  int n, m;
  cin >> n >> m;
 
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		parent[i] = i;
		sum[i] = x;
	}
 
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
 
		if(getParent(a) != getParent(b)) unionParent(a, b);
 
		if(a > b) cout << sum[getParent(b)] << endl;
		else cout << sum[getParent(a)] << endl;
	}
	return 0;
}
