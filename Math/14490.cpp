#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	string s;
	cin >> s;
	
	int idx = s.find(":");
	int n = stoi(s.substr(0, idx));
	int m = stoi(s.substr(idx + 1, -1));
	int gcf = gcd(n, m);
	
	cout << n / gcf << ":" << m / gcf;
	return 0;
}
