#include <iostream>
using namespace std;

int n, x;
int arr[250000];

int main() {
	cin >> n >> x;
	
	int sum = 0;
	for(int i = 0; i < x; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	int ans = sum;
	int cnt = 1;
	for(int i = x; i < n; i++){
		cin >> arr[i];
		sum += arr[i] - arr[i - x];
		if(sum == ans){
			cnt++;
		} else if(sum > ans){
			ans = sum;
			cnt = 1;
		}
	}
	if(ans == 0) cout << "SAD";
	else{
		cout << ans << endl;
		cout << cnt << endl;
	}
	return 0;
}
