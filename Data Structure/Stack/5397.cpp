#include <iostream>
#include <stack>
using namespace std;

int n;

int main() {
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;

		string pwd;
		stack<char> st;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '<') {
				if (!pwd.empty()) {
					st.push(pwd[pwd.length() - 1]);
					pwd.pop_back();
				}
			}
			else if (str[j] == '>') {
				if (!st.empty()) {
					pwd.push_back(st.top());
					st.pop();
				}
			}
			else if (str[j] == '-') {
				if (!pwd.empty()) pwd.pop_back();
			}
			else {
				pwd.push_back(str[j]);
			}
		}

		while (!st.empty()) {
			pwd.push_back(st.top());
			st.pop();
		}

		cout << pwd << '\n';
	}
}
