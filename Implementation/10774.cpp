#include <iostream>
#include <vector>
using namespace std;

int main() {
	int j, a;
	cin >> j >> a;
	vector<int> jsize; // S:0, M:1, L:2
	jsize.push_back(0);
	for(int i = 0; i < j; i++){
		char sz;
		cin >> sz;
		if(sz == 'S') jsize.push_back(0);
		else if(sz == 'M') jsize.push_back(1);
		else jsize.push_back(2);
	}
	vector<bool> used(jsize.size());
	int answer = 0;
	for(int i = 0; i < a; i++){
		char sz; int num;
		cin >> sz >> num;
		int nsz;
		if(sz == 'S') nsz = 0;
		else if(sz == 'M') nsz = 1;
		else nsz = 2;
		if(jsize[num] >= nsz && !used[num]) {
			used[num] = true;
			answer++;
		}
	}
	cout << answer;
	return 0;
}
