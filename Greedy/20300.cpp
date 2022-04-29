#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long t;
	cin >> n;
	
	vector<long long> v;
	for(int i = 0; i < n; i++){
		cin >> t;
		v.push_back(t);
	}
	
	sort(v.begin(), v.end());
	
	long long max = 0;
	if(n % 2 == 0){
		for(int i = 0; i < n / 2; i++){
			if(v[i] + v[n - i - 1] > max) max = v[i] + v[n - i - 1];
 		}
	} else{
		max = v[n - 1];
		for(int i = 0; i < (n - 1) / 2; i++){
			if(v[i] + v[n - i - 2] > max) max = v[i] + v[n - i - 2];
 		}
	}
	
	cout << max << endl;
	return 0;
}
