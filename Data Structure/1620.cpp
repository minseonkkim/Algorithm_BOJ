#include <iostream>
#include <map>
#include <string>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, m;
	cin >> n >> m;
 
	map<int, string> m1;
	map<string, int> m2;
	string s;
	for(int i = 1; i <= n; i++){
		cin >> s;
		m1.insert(make_pair(i, s));
		m2.insert(make_pair(s, i));
	}
 
	for(int i = 0; i < m; i++){
		cin >> s;
		if('0' <= s[0] && s[0] <= '9'){
			int idx = stoi(s);
			cout << m1[idx] << '\n';
		} else{
			cout << m2[s] << '\n';
		}
	}
	return 0;
}
