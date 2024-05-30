#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n;
map<string, bool, greater<string>> m;

int main() {
	cin >> n;
	string name, cmd;
	for (int i = 0; i < n; i++) {
		cin >> name >> cmd;
		if (cmd == "enter") {
			m[name] = true;
		}
		else {
			m[name] = false;
		}
	}

	for (auto x : m) {
		if (x.second == true) {
			cout << x.first << '\n';
		}
	}
}
