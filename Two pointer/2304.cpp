#include <iostream>
using namespace std;

int n;
int arr[1001];
int max_l, max_h;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		int l, h;
		cin >> l >> h;
		arr[l] = h;
		if(h > max_h){
			max_l = l;
			max_h = h;
		}
	}
	
	int lh = 0;
	for(int i = 1; i < max_l; i++){
		if(arr[i] > lh) lh = arr[i];
		ans += lh;
	}
	
	int rh = 0;
	for(int i = 1000; i > max_l; i--){
		if(arr[i] > rh) rh = arr[i];
		ans += rh;
	}
	
	cout << ans + max_h << endl;
	return 0;
}
