#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, c;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin >> c;
		v.push_back(c);
	}
	
	sort(v.begin(), v.end(), greater<>());
	
	int sum = 0;
	for(int i = 0; i < n; i++){
		if((i + 1) % 3 == 0) continue;
		sum += v[i];
	}
	
	cout << sum << endl;
	return 0;
}
