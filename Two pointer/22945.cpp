#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	int l = 0;
	int r = v.size() - 1;
	
	int max = 0;
	while(l < r){
		int a = (r - l - 1) * min(v[l], v[r]);
		if(a > max) max = a;
		
		if(v[l] < v[r]) l++;
		else r--;
	}
	cout << max << endl;
	return 0;
}
