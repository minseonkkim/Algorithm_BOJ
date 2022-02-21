#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	double num;
	vector<double> v;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	
	double sum = v[n - 1];
	for(int i = 0; i < n - 1; i++){
		if(v[i] < sum) sum += v[i] / 2;
		else sum = sum / 2 + v[i];
	}
	cout << sum << endl;
	return 0;
}
