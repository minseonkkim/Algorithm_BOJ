#include <iostream>
using namespace std;

int n;
bool isShorten[26];

int main() {
	cin >> n;
	cin.ignore();
	
	for(int i = 0; i < n; i++){
		string str;
		getline(cin, str);
		// 1.
		bool isFind = false;
		string output = "";
		char c = islower(str[0]) ? toupper(str[0]) : str[0];
		if(!isShorten[c - 'A']){
			isShorten[c - 'A'] = true;
			output += "[";
			output += str[0];
			output += "]";
			output += str.substr(1);
			isFind = true;
		}
		if(isFind) {
			cout << output << '\n';
			continue;
		}
		
		output = str[0];
		for(int j = 1; j < str.length(); j++){
			if(!isFind && str[j] == ' ' && j + 1 < str.length()){
				c = islower(str[j + 1]) ? toupper(str[j + 1]) : str[j + 1];
				if(!isShorten[c - 'A']){
					isShorten[c - 'A'] = true;
					output += " [";
					output += str[j + 1];
					output += "]";
					isFind = true;
					j++;
				} else{
					output += str[j];
				}
			} else{
				output += str[j];
			}
		}
		if(isFind) {
			cout << output << '\n';
			continue;
		}

		
		// 2.
		output = "";
		for(int j = 0; j < str.length(); j++){
			if(str[j] == ' ') {
				output += ' ';
				continue;
			}
			char c = islower(str[j]) ? toupper(str[j]) : str[j];
			if(!isFind && !isShorten[c - 'A']){
				isShorten[c - 'A'] = true;
				output += "[";
				output += str[j];
				output += "]";
				isFind = true;
			} else{
				output += str[j];
			}
		}
		if(isFind) {
			cout << output << '\n';
			continue;
		}
		
		// 3.
		cout << str << '\n';
	}
	return 0;
}
