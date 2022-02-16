#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, k;
	cin >> n;
	
	vector<int> v;
	for(int i = 0; i < n; i++){	
		cin >> k;
		v.push_back(k);
	}
	
	cin >> m;
	sort(v.begin(), v.end());
	for(int i = 0; i < m; i++){	
		cin >> k;
		if(binary_search(v.begin(), v.end(), k)) cout << 1 << " ";
		else cout << 0 << " ";
	}
	
	return 0;
}
