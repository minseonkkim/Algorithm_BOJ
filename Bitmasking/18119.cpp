#include <iostream>
using namespace std;

int n, m;
int word[10000];

int main() {
	cin >> n >> m;
	
	int remember = 0;
	remember |= ((1 << 26) - 1);
	
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < s.size(); j++){
			word[i] |= (1 << (s[j] - 'a'));
		}
	}
	for(int i = 0; i < m; i++){
		int o; char x;
		cin >> o >> x;
		
		remember ^= (1 << (x - 'a'));
		
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if((word[j] & remember) == word[j]) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
