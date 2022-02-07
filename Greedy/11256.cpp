#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, j, n, r, c;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		vector<int> v;
		int cnt = 0;
		cin >> j >> n;
		for(int k = 0; k < n; k++){
			cin >> r >> c;
			v.push_back(r * c);
		}
	
		sort(v.begin(), v.end(), compare);
		
		while(j > 0 || v.empty()){
			j -= v.front();
			v.erase(v.begin());
			cnt++;
		}
		
		v.clear();
		cout << cnt << endl;
	}
	return 0;
}
