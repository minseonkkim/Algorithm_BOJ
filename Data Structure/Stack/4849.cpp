#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	while(true){
		string str;
		getline(cin, str);
		if(str == ".") break;
		
		stack<char> st;
		string ans = "yes";
	
		for(int i = 0; i < str.length(); i++){
			if(str[i] == '(') st.push('(');
			else if(str[i] == '[') st.push('[');
			else if(str[i] == ')'){
				if(st.empty() || st.top() == '['){
					ans = "no";
					break;
				} else{
					st.pop();
				}
			}
			else if(str[i] == ']'){
				if(st.empty() || st.top() == '('){
					ans = "no";
					break;
				} else{
					st.pop();
				}
			}
		}
		if(!st.empty()) ans = "no";
		cout << ans << endl;
	}
	return 0;
}
