#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> v;
long long ret = 1e18;
long long ans[3];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		long long x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n - 2; i++){
		long long start = i + 1;
		long long end = n - 1;
		while(start < end){
			long long sum = v[i] + v[start] + v[end];
			if(abs(sum) < ret){
				ret = abs(sum);
				ans[0] = v[i];
				ans[1] = v[start];
				ans[2] = v[end];
			}
			if(sum < 0) start++;
			else end--;
		}
	}
	cout << ans[0] << " " << ans[1] << " " << ans[2];
	return 0;
}
