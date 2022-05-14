#include <iostream>
#include <algorithm>
using namespace std;
 
int house[1001][3];
 
int main() {
	int n;
	cin >> n;
 
	int r, g, b;
	for(int i = 1; i <= n; i++){
		cin >> r >> g >> b;
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + r;
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + g;
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + b;
	}
 
	cout << min(house[n][0], min(house[n][1], house[n][2]));
	return 0;
}
