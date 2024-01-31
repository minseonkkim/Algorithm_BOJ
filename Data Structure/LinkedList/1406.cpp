#include <iostream>
#include <list>
using namespace std;

int main() {
	list<char> li;
	auto it = li.end();
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		li.push_back(s[i]);
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		char cmd;
		cin >> cmd;
		if(cmd == 'L'){
			if(it != li.begin()) it--;
		} else if(cmd == 'D'){
			if(it != li.end()) it++;
		} else if(cmd == 'B'){
			if(it != li.begin()){
				it--;
				it = li.erase(it);
			}
		} else if(cmd == 'P'){
			char c;
			cin >> c;
			li.insert(it, c);
		}
	}
	
	string ans = "";
	for(auto it = li.begin(); it != li.end(); it++){
		ans += *it;
	}
	cout << ans;
	return 0;
}
