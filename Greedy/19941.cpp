#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	bool ate[20000] = {false, };
	
	int ans = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'P'){
			int start = i - k < 0 ? 0 : i - k;
			int end = i + k >= s.length() ? s.length() - 1 : i + k;
			for(int j = start; j <= end; j++){
				if(s[j] == 'H' && ate[j] == false){
					ate[j] = true;
					ans++;
					break;
				}			
			}
		}
	}
	cout << ans;
	return 0;
}
