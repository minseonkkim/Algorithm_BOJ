#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	
	for(int i = 0; i < n; i++){
		stack<char> s;
		string str;
		cin >> str;
		
		bool check = true;
		for(int j = 0; j < str.length(); j++){
			char c = str[j];
			
			if(c == '('){
				s.push(str[j]);
			} else{
				if(!s.empty()) {
					s.pop();
				} else {
					check = false;
					break;
				}
			}
		}
		
		if(!s.empty()) check = false;
		
		if(check)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
