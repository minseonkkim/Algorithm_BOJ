#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	string s;
	cin >> s;
 
	sort(s.begin(), s.end());
 
	int cnt = 0;
	do{
		bool islucky = true;
		for(int i = 1; i < s.length(); i++){
			if(s[i] == s[i - 1]) {
				islucky = false;
				break;
			}
		}
		if(islucky) cnt++;
	}while(next_permutation(s.begin(), s.end()));
 
	cout << cnt;
	return 0;
}
