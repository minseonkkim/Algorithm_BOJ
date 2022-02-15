#include <iostream>
using namespace std;

int main() {
	int a1, a0, c1, c2, n;
	cin >> a1 >> a0 >> c1 >> c2 >> n;

	for(int i = n; i <= 100; i++){
		if(a1 * i + a0 < c1 * i || a1 * i + a0 > c2 * i){
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}
