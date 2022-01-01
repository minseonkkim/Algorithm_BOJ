#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int num) {
    if (num == 2) return true;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }

    return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	int last = 0;
	int i = 2;
	int sum;
	while(true){
		if(is_prime(i)){
			sum = last * i;
			if(sum > n){
				break;
			}
			last = i;
		}
		i++;
	}
	cout << sum << endl;
	return 0;
}
