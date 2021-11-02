#include <iostream>
#include <list>
using namespace std;

int main() {
	int num, n;
	cin >> num;

	list<int> l;

	for (int i = 0; i < num; i++) {
		cin >> n;
		l.push_back(n);
	}

	l.sort();
	l.unique();

	list<int>::iterator iter;
	for (iter = l.begin(); iter != l.end(); iter++) {
		cout << *iter << " ";
	}
	return 0;
}
