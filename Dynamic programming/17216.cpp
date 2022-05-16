#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	vector<int> arr(n);
	vector<int> dp(n);
 
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
 
	int answer = 0;
	for(int y = 0; y < n; y++){
        dp[y] = arr[y];
		for(int x = 0; x < y; x++){
			if(arr[x] > arr[y]){
				dp[y] = max(dp[y], dp[x] + arr[y]);
			}
		}
		answer = max(answer, dp[y]);
	}
 
	cout << answer << endl;
	return 0;
}
