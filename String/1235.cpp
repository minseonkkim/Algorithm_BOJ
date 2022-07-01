#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s[1000];
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	int ans = s[0].size();
	for(int i = 0; i < s[0].size(); i++){
		set<string> st;
		for(int j = 0; j < n; j++){
			st.insert(s[j].substr(s[0].size() - 1 - i));
		}
		if(st.size() == n){
			ans = i + 1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
