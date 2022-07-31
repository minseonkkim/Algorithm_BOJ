#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long m, n;
	cin >> m >> n;
	
	vector<long long> v;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	long long min = 1;
	long long max = v[n - 1];
	long long ans = 0;
	
	while(min <= max){
		long long cnt = 0;
		long long mid = (min + max) / 2;
		for(int i = 0; i < n; i++){
			cnt += v[i] / mid;
		}
		if(cnt >= m){
			min = mid + 1;
			ans = mid;
		}else{
			max = mid - 1;
		}
	}
	
	cout << ans << endl;
	return 0;
}
