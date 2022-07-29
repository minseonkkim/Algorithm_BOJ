#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	
	vector<long long> v(n);
	long long min = 0, max = 0;
	long long result = 0;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(v[i] > max) max = v[i];
	}
	
	while(min <= max){
		long long mid = (min + max) / 2;
		long long total = 0;
		for(int i = 0; i < n; i++){
			if(mid < v[i]) total += v[i] - mid;
		}
		
		if(total >= m){
			if(result < mid) result = mid;
			min = mid + 1;
		}else{
			max = mid - 1;
		}
	}
	
	cout << result << endl;
	
	return 0;
}
