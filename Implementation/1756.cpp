#include <iostream>
using namespace std;

int d, n;
int diameter[300001];
int pizza[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> d >> n;
	for(int i = 1; i <= d; i++) {
		int dmt;
		cin >> dmt;
		if(i != 1 && dmt > diameter[i - 1]) diameter[i] = diameter[i - 1];
		else diameter[i] = dmt;
	}
	for(int i = 1; i <= n; i++) cin >> pizza[i];
	
	int idx = 1;
	for(int i = d; i >= 1; i--){
		if(pizza[idx] <= diameter[i]) {
			if(idx == n){
				cout << i;
				return 0;
			}
			else idx++;
		}
	}
	cout << 0;
	return 0;
}
