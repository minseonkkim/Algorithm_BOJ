#include <iostream>
using namespace std;

int main() {
	int a[10001];
	int n, k, loc, newItem, cnt = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i < n; i++){
		loc = i - 1;
		newItem = a[i];
		
		while(0 <= loc && newItem < a[loc]){
			a[loc + 1] = a[loc];
			loc--;
			cnt++;
			if(cnt == k){
				cout << a[loc + 1] << endl;
				return 0;
			}
		}
		if(loc + 1 != i) {
			a[loc + 1] = newItem;
			cnt++;
			if(cnt == k){
				cout << a[loc + 1] << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
