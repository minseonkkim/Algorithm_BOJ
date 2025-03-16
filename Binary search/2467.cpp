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
	
	long long min = 987654321;
	long long a = 0;
	long long b = 0;
	int l = 0;
	int r = v.size() - 1;
	while(l < r){
		int sum = v[l] + v[r];
		if(abs(sum) < min){
			min = abs(sum);
			a = v[l];
			b = v[r];
		}
		if(sum <= 0) l++;
		else r--;
	}
	cout << a << " " << b << endl;
	return 0;
}
