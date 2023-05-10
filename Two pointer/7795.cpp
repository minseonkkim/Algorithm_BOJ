#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		vector<int> a;
		vector<int> b;
		
		int n, m;
		cin >> n >> m;
		
		for(int j = 0; j < n; j++){
			int x;
			cin >> x;
			a.push_back(x);
		}
		for(int j = 0; j < m; j++){
			int x;
			cin >> x;
			b.push_back(x);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		int point = 0, ans = 0;
		for(int j = 0; j < n; j++){
			while(point < m && a[j] > b[point]){
				point++;
			}
			ans += point;
		}
		cout << ans << endl;
	}
	return 0;
}
