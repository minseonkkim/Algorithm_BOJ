#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n, m, t, power;
	string name;
	vector<int> iv;
	vector<string> sv;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> name >> t;
		sv.push_back(name);
		iv.push_back(t);
	}
	for(int i = 0; i < m; i++){
		cin >> power;
		cout << sv[lower_bound(iv.begin(), iv.end(), power) - iv.begin()] << "\n";
	}
	return 0;
}
