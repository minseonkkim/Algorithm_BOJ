#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<char> s;
	stack<char> t;
	string str;
	cin >> str;
	
	for(int i = 0; i < str.length(); i++){
		char c = str[i];
		
		if(c == '('){
			s.push(str[i]);
		} else {
			if(!s.empty()) s.pop();
			else t.push(str[i]);
		}
	}
	
	cout << s.size() + t.size() << endl;
	
	return 0;
}
