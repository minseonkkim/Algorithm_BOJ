#include <iostream>
#include <bitset>
using namespace std;
 
bitset<33554432> bits;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;
	while(cin >> n){
		if(!bits[n]){
			bits[n] = 1;
			cout << n << ' ';
		}
	}
	return 0;
}
