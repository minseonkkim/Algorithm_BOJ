#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long k;
	vector<long long> v;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	
	int t = 0;
	int max = 0;
	long long ans;
	while(t < n){
		long long nn = v[t];
		int num = upper_bound(v.begin(), v.end(), nn) - lower_bound(v.begin(), v.end(), nn);
		if(num > max) {
			max = num;
			ans = v[t];
		}
		t = upper_bound(v.begin(), v.end(), nn) - v.begin() + 1;
	}
	
	cout << ans << endl;
	return 0;
}
