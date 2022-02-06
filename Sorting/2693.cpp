#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
	return a > b;
}

int main() {
	int n, num;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10; j++){
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end(), compare);
		cout << v[2] << endl;
		v.clear();
	}
	return 0;
}
