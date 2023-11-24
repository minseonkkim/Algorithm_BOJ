#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<string, bool> mp;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		mp[s] = true;
	}
	int cnt = 0;
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		if(mp[s]) cnt++;
	}
	cout << cnt;
	return 0;
}
