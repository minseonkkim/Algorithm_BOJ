#include <iostream>
using namespace std;

int main() {
    int Z[41] = { 1, 0 };
    int O[41] = { 0, 1 };

    for (int i = 2; i <= 40; i++) {
        Z[i] = Z[i - 1] + Z[i - 2];
        O[i] = O[i - 1] + O[i - 2];
    }

    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << Z[n] << " " << O[n] << "\n";
    }

	return 0;
}
