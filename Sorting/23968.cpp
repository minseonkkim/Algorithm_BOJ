#include <iostream>
using namespace std;

int main() {
	int n, k, cnt = 0;
	int v[10001];
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for(int i = n - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j] > v[j + 1]){
				int t = v[j];
				v[j] = v[j + 1];
				v[j + 1] = t;
				cnt++;
				if(cnt == k){
					cout << v[j] << " " << v[j + 1] << endl;
					return 0;
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
