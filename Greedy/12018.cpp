#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, num, p, l;
	cin >> n >> m;
  
	vector<int> vv;
	for(int i = 0; i < n; i++){
		cin >> p >> l;
		vector<int> v;
		for(int j = 0; j < p; j++){
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end(), greater<>());
		if(v.size() < l) vv.push_back(1);
		else vv.push_back(v[l - 1]);
	}
  
	sort(vv.begin(), vv.end());
  
	int i = 0;
	for(i = 0; i < vv.size(); i++){
		m -= vv[i];
		if(m < 0) break;
	}
	cout << i << endl;
	return 0;
}
