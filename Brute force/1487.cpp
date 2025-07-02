#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
	cin >> n;
	int delivery_fee_sum = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
		delivery_fee_sum += b;
	}
	sort(v.begin(), v.end());
	int answer = 0, maxprofit = 0;
	for(int i = 0; i < n; i++){
		int profit = 0;
		for(int j = i; j < n; j++){
			int curprofit = v[i].first - v[j].second;
			if(curprofit > 0) profit += curprofit;
		}
		if(profit > maxprofit){
			maxprofit = profit;
			answer = v[i].first;
		}
	}
	cout << answer;
	return 0;
}
