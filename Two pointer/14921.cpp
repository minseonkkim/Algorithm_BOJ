#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> v;
	int t;
	for(int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}
	
	long long min = 9876543210;
	long long ans = 0;
	int l = 0;
	int r = v.size() - 1;
	while(l < r){
		int sum = v[l] + v[r];
		if(abs(sum) < min){
			min = abs(sum);
			ans = sum;
		}
		if(sum <= 0) l++;
		else r--;
	}
	cout << ans << endl;
	return 0;
}
