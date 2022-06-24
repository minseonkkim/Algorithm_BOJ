#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		string s, p;
		cin >> s >> p;
		int cnt = 0;
		int stt = 0;
		while(1){
			int st = s.find(p, stt);
			if(st == -1) break;
			cnt++;
			stt = st + p.length();
		}
		
		cout << s.length() - p.length() * cnt + cnt << endl;
	}
	return 0;
}
