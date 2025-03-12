#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	unordered_map<string, int> um;
	vector<string> outp;
	int answer = 0;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		um[s] = i;
	}
	outp.push_back("");
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		outp.push_back(s);
	}
	for(int i = 1; i <= n - 1; i++){
		for(int j = i + 1; j <= n; j++){
			if(um[outp[i]] > um[outp[j]]) {
				answer++;
				break;
			}
		}
	}
	cout << answer;
	return 0;
}
