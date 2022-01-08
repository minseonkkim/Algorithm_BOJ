#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, cnt = 0;
	cin >> n;
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		set<char> s;
		char last = ' ';
		bool isTrue = true;
		for(int j = 0; j < str.length(); j++){
			if(last == str[j]){
				continue;
			} else{
				if(s.find(str[j]) != s.end()){
					isTrue = false;
					break;
				} 
				s.insert(str[j]);
				last = str[j];
			}
		}
		if(isTrue) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
