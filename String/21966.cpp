#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string s;
	
	cin >> n >> s;
	
	string sub = s.substr(11, n - 22);
	int in = sub.find(".");
	
	if(n <= 25) cout << s << endl;
	else if(in == sub.size() - 1 || in == -1){
		cout << s.substr(0, 11) << "..." << s.substr(s.size() -11, 11);
	} 
	else{
		cout << s.substr(0, 9) << "......" << s.substr(s.size() -10, 10);
	}
	return 0;
}
