#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	vector<string> v;
	vector<string> t;
	string s, k;
	for(int i = 0; i < n; i++){
		cin >> s;
		v.push_back(s);
	}
	
	sort(v.begin(), v.end());
	for(int i = 0; i < m; i++){
		cin >> k;
		if(binary_search(v.begin(), v.end(), k)) t.push_back(k);
	}
	
	cout << t.size() << '\n';
	sort(t.begin(), t.end());
	for(string r : t){
		cout << r << '\n';
	}
	
	return 0;
}
