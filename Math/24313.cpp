#include <iostream>
using namespace std;

int main() {
	int a1, a0, c, n;
	cin >> a1 >> a0 >> c >> n;

	for(int i = n; i <= 100; i++){
		if(a1 * i + a0 > c * i){
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}
