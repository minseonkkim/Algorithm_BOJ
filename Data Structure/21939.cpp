#include <iostream>
#include <set>
#include <map>
using namespace std;

int a, b;
set<pair<int, int>> s;
map<int, int> m;

int main() {
	cin >> a;
	for (int i = 0; i < a; i++) {
		int p, l;
		cin >> p >> l;
		s.insert({ l, p });
		m[p] = l;
	}
	cin >> b;
	for (int i = 0; i < b; i++) {
		string command;
		cin >> command;
		if (command == "recommend") {
			int x;
			cin >> x;
			if (x == 1) {
				auto it = s.rbegin();
				cout << it->second << '\n';
			}
			else if (x == -1) {
				auto it = s.begin();
				cout << it->second << '\n';
			}
		}
		else if (command == "add") {
			int p, l;
			cin >> p >> l;
			s.insert({ l, p });
			m[p] = l;
		}
		else if (command == "solved") {
			int p;
			cin >> p;
			s.erase({ m[p], p });
		}
	}
	return 0;
}
