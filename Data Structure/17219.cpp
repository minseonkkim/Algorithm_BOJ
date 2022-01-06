#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	map<string, string> m;
	string s1, s2;
	for(int i = 0; i < n; i++){
		cin >> s1;
		cin >> s2;
		
		m.insert(make_pair(s1, s2));
	}
	string s;
	for(int i = 0; i < k; i++){
		cin >> s;
		cout << m[s] << endl;
	}
	return 0;
}
