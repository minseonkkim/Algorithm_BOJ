#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s;
int cnt[26];

int main(){
	cin >> n >> s;
	int l = 0, r = 0, kind = 0, maxlen = 0;
	while(r < s.length()){
		if(cnt[s[r] - 'a'] == 0) kind++;
		cnt[s[r++] - 'a']++;
		
		while(kind > n){
			cnt[s[l] - 'a']--;
			if(cnt[s[l++] - 'a'] == 0) kind--;
		}
		
		maxlen = max(maxlen, r - l);
	}
	cout << maxlen;
	return 0;
}
