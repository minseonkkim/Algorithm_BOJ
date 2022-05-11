#include <iostream> 
using namespace std;

int main() {
	int n;
	cin >> n;

	bool isvisited[10] = { false, };
	int num, prev;
	cin >> num;
	isvisited[num] = true;
	prev = num;
	for (int i = 1; i < n; i++) {
		cin >> num;
		if (isvisited[num]) {
			cout << "NO" << endl;
			return 0;
		}
		if (!isvisited[2] && (num == 1 && prev == 3 || num == 3 && prev == 1)) {
			cout << "NO" << endl;
			return 0;
		}
		if (!isvisited[4] && (num == 1 && prev == 7 || num == 7 && prev == 1)) {
			cout << "NO" << endl;
			return 0;
		}
		if (!isvisited[5] && ((num == 1 && prev == 9 || num == 9 && prev == 1) ||
			(num == 2 && prev == 8 || num == 8 && prev == 2) ||
			(num == 3 && prev == 7 || num == 7 && prev == 3) ||
			(num == 4 && prev == 6 || num == 6 && prev == 4))) {
			cout << "NO" << endl;
			return 0;
		}
		if (!isvisited[6] && (num == 3 && prev == 9 || num == 9 && prev == 3)) {
			cout << "NO" << endl;
			return 0;
		}
		if (!isvisited[8] && (num == 7 && prev == 9 || num == 9 && prev == 7)) {
			cout << "NO" << endl;
			return 0;
		}
		isvisited[num] = true;
		prev = num;
	}
	cout << "YES" << endl;
	return 0;
}
