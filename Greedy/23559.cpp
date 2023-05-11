#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, x;
	cin >> n >> x;
	
	vector<int> v;
	int sum = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		sum += b;
		x -= 1000;
		v.push_back(a - b);
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i = 0; i < v.size(); i++){
		if(x - 4000 >= 0 && v[i] >= 0){
			x -= 4000;
			sum += v[i];
		} 
	}
	
	cout << sum << endl;
	return 0;
}
