#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
vector<int> v;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		v.push_back(data);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		int f;
		cin >> f;
		
		int ind = lower_bound(v.begin(), v.end(), f) - v.begin();
		if (ind!=n&&v[ind] == f) {
			cout << ind << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
	return 0;
}
