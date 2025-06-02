#include <iostream>
using namespace std;

long long a, b, cnt;

void func(long long num){
	if(num >= a){
		if(num <= b) cnt++;
		else return;
	}
	
	func(10 * num + 4);
	func(10 * num + 7);
}

int main() {
	cin >> a >> b;
	
	func(4);
	func(7);
	
	cout << cnt;
	return 0;
}
