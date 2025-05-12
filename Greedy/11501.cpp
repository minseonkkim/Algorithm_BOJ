#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int tc = 0; tc < t; tc++){
		int n;
		cin >> n;
        vector<int> prices;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			prices.push_back(x);
		}
		
		int max_price = -1;
        long long answer = 0;
		for(int i = n - 1; i >= 0; i--){
			max_price = max(max_price, prices[i]);
			answer += max_price - prices[i];
		}
		cout << answer << '\n';
	}
	return 0;
}
