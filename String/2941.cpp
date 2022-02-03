#include <iostream>
#include <string>
using namespace std;
 
int main() {
	string cro[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string str;
	cin >> str;
 
	for(int i = 0; i < 8; i++){
		while(1){
			int idx = str.find(cro[i]);
			if(idx == -1) break;
			if(i == 2){
				str.replace(idx, 3, "#");
			} else{
				str.replace(idx, 2, "#");
			}
		}
	}
 
	cout << str.size() << endl;
 
	return 0;
}
