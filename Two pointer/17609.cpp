#include <iostream>
using namespace std;

string s;

int isPalindrome(int l, int r, bool used){
	while(l < r){
		if(s[l] != s[r]){
			if(!used){
				if(isPalindrome(l + 1, r, true) == 0 || isPalindrome(l, r - 1, true) == 0) return 1;
			}
			return 2;
		}
		l++;
		r--;
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> s;
		cout << isPalindrome(0, s.length() - 1, false) << '\n';
	}
	return 0;
}
