#include <iostream>
#include <bitset>
using namespace std;

bitset<2000> bits[2000];
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		bits[i] = bitset<2000>(s);
	}
	cin >> m;
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		cout << (bits[a - 1] & bits[b - 1]).count() << '\n';
	}
	return 0;
}
