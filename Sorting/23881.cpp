#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k, num, cnt = 0;
	int v[10001];
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for(int i = n - 1; i >= 1; i--){
		int max = i;
		for(int j = 0; j < i; j++){
			if(v[j] > v[max])
				max = j;
		}
		if(max != i){
			int t = v[i];
			v[i] = v[max];
			v[max] = t;
			cnt++;
			if(cnt == k) {
				if(v[i] > v[max]) cout << v[max] << " " << v[i] << endl;
				else cout << v[i] << " " << v[max] << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
