#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> volume;

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		volume.push_back(x);
	}
	long long l = 0, r = 1e32, result = 0;
	while(l <= r){
		long long mid = (l + r) / 2;
		
		int cnt = 0;
		for(int i = 0; i < volume.size(); i++){
			cnt += volume[i] / mid;
		}
		
		if(cnt < k){
			r = mid - 1;
		} else{
			l = mid + 1;
			result = mid;
		}
	}
	cout << result;
	return 0;
}
