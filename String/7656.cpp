#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	getline(cin, str);
	
	int start, end = -1;
	while(str.find("What", end + 1) != -1){
		start = str.find("What", end + 1);
		end = str.find("?", start + 1);
		string s = str.substr(start, end - start + 1);

		if(s.find(".") != -1){
			end = str.find(".", start + 1);
			continue;
		}
		s.replace(0, 4, "Forty-two");
		s.replace(s.length()-1, 1, ".");
		cout << s << endl;
	}
	return 0;
}
