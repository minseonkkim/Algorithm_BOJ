#include <iostream>
using namespace std;

int main() {
	string str; int n;
	cin >> str >> n;
	
	int strlen = str.length();
	int answer = 0;
	
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		int slen = s.length();
		s += s;
		bool find = false;
		for(int j = 0; j < slen; j++){
			if(s.substr(j, strlen) == str){
				find = true;
				break;
			}
		}
		if(find) answer++;
	}
	cout << answer;
	return 0;
}
