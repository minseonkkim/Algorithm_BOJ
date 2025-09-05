#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int tc = 0; tc < t; tc++){
		int n;
		cin >> n;
		
		string str[11] = {"", };
		for(int i = 1; i <= n; i++){
			cin >> str[i];
		}
		bool dead[11] = {false, };
		for(int i = 0; i < str[1].length(); i++){
			int cnt[3] = {0, };
			for(int j = 1; j <= n; j++){
				if(dead[j]) continue;
				if(str[j][i] == 'R') cnt[0]++;
				else if(str[j][i] == 'S') cnt[1]++;
				else cnt[2]++;
			}
			int cntzero = 0;
			for(int j = 0; j < 3; j++){
				if(cnt[j] == 0) cntzero++;
			}
			if(cntzero == 1){
				if(cnt[0] == 0){
					for(int j = 1; j <= n; j++){
						if(dead[j]) continue;
						if(str[j][i] != 'S') dead[j] = true;
					}
				} else if(cnt[1] == 0){
					for(int j = 1; j <= n; j++){
						if(dead[j]) continue;
						if(str[j][i] != 'P') dead[j] = true;
					}
				} else if(cnt[2] == 0){
					for(int j = 1; j <= n; j++){
						if(dead[j]) continue;
						if(str[j][i] != 'R') dead[j] = true;
					}
				}
			}
		}
		int cntservive = 0;
		int survivenum = 0;
		for(int i = 1; i <= n; i++){
			if(!dead[i]) {
				cntservive++;
				survivenum = i;
			}
		}
		if(cntservive == 1) cout << survivenum << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}
