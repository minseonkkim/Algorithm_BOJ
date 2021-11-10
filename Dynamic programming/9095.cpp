#include <iostream>
using namespace std;
 
int rec(int n) {
	if (n == 1) return 1;
	if(n == 2) return 2;
	if(n == 3) return 4;
	return rec(n - 1) + rec(n - 2) + rec(n - 3);
}
 
int main() {
	int n, num;
	cin >> n;
 
	for (int i = 0; i < n; i++) {
		cin >> num;
		cout << rec(num) << endl;
	}
	return 0;
}
