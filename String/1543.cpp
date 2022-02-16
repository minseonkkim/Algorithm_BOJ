#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	
	int s = 0, cnt = 0;
	while(1){
		int t = s1.find(s2, s);
		if(t == -1) break;
		s = t + s2.size();
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
