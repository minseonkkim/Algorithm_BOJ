#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[100000];

int main() {
	cin >> n >> k;
	int sum = 0;
	for(int i = 0; i < k; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	int ans = sum;
	for(int i = k; i < n; i++){
		cin >> arr[i];
		sum += arr[i] - arr[i - k]; 
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}
