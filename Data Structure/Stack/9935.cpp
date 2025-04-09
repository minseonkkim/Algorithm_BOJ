#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	string str, bomb;
	cin >> str >> bomb;
	
	stack<char> st;
	
	for(int i = 0; i < str.length(); i++){
		int ch = str[i];
		st.push(ch);
		if(ch == bomb[bomb.length() - 1] && st.size() >= bomb.length()){
			string tmp;
			for(int j = 0; j < bomb.length(); j++){
				tmp += st.top();
				st.pop();
			}
			reverse(tmp.begin(), tmp.end());
			if(tmp != bomb){
				for(int j = 0; j < tmp.size(); j++){
					st.push(tmp[j]);
				}
			} 
		}
	}
	
	if(st.empty()){
		cout << "FRULA";
		return 0;
	}
	
	string ans = "";
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
