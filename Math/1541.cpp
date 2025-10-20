#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int start = 0, answer = 0;
	bool minus = false;
	for(int i = 0; i < str.length(); i++){
		char c = str[i];
		
		if(c == '+' || c == '-'){
			string s = str.substr(start, i - start + 1);
			if(minus) answer -= stoi(s);
			else answer += stoi(s);
			start = i + 1;
		}
		
		if(c == '-') minus = true;
	} 
	string s = str.substr(start);
	if(minus) answer -= stoi(s);
	else answer += stoi(s);
	cout << answer;
	return 0;
}
