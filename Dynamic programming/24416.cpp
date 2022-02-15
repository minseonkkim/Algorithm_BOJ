#include <iostream>
using namespace std;

int cnt1 = 0, cnt2 = 0;

int fib(int n){
	if(n == 1 || n == 2) {
		cnt1++;
		return 1;
	}
	else return fib(n - 1) + fib(n - 2);
}

int main() {
	int n;
	cin >> n;

	for(int i = 3; i <= n; i++){
		cnt2++;
	}
	
	fib(n);
	
	cout << cnt1 << " " << cnt2 << endl;
	return 0;
}
