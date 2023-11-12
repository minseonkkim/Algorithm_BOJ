#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		string buf;
		getline(cin, buf);
		string s;
		getline(cin, s);
		
		map<string, bool> m;
		while(true){
			string a, b, c;
			cin >> a >> b >> c;
			if(a == "what"){
				cin >> b >> c;
				break;
			}
			m[c] = true;
		}
		
		string tmp = "";
		for(int i = 0; i < s.length(); i++){
			if(s[i] == ' '){
				if(!m[tmp]) cout << tmp << " ";
				tmp = "";
			} else{
				tmp += s[i];
			}
		}
		if(!m[tmp]) cout << tmp << " ";
		cout << '\n';
	}
	return 0;
}
