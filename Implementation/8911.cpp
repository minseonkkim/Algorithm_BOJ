#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	int t;
	cin >> t;
	for(int tc = 0; tc < t; tc++){
		string cmd;
		cin >> cmd;
		int cx = 0, cy = 0, cd = 0;
		int mt = 0, mb = 0, ml = 0, mr = 0;
		for(int i = 0; i < cmd.length(); i++){
			if(cmd[i] == 'F'){
				cx += dx[cd];
				cy += dy[cd];
				if(cx > 0) mr = max(mr, cx);
				else ml = min(ml, cx);
				if(cy > 0) mt = max(mt, cy);
				else mb = min(mb, cy);
			} else if(cmd[i] == 'B'){
				cx -= dx[cd];
				cy -= dy[cd];
				if(cx > 0) mr = max(mr, cx);
				else ml = min(ml, cx);
				if(cy > 0) mt = max(mt, cy);
				else mb = min(mb, cy);
			} else if(cmd[i] == 'L'){
				cd = (cd - 1 == -1) ? 3 : cd - 1;
			} else{
				cd = (cd + 1 == 4) ? 0 : cd + 1;
			}
		}
		
		int x = abs(ml) + mr;
		int y = abs(mb) + mt;
		cout << x * y << '\n';
	}
	return 0;
}
