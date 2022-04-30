#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k, answer = 0;
	cin >> n >> k;
	
	vector<int> tap(n, -1);
	vector<int> v(k);
	
	for(int i = 0; i < k; i++){
		cin >> v[i];
	}

	
	for(int i = 0; i < k; i++){
		// 이미 꽂혀있는 경우
		if(find(tap.begin(), tap.end(), v[i]) != tap.end()) continue;
		
		bool isplugged = false;
		// 비어있는 콘센트가 있는 경우
		for(int j = 0; j < n; j++){
			if(tap[j] == -1) {
				tap[j] = v[i];
				isplugged = true;
				break;
			}
		}
		if(isplugged) continue;
		
		// 이미 꽂혀있지 않고 비어있는 콘센트가 없는 경우
		int last = -1, index = -1;
		for(int j = 0; j < n; j++){
			int tmp = 0;
			for(int t = i + 1; t < k; t++){
				if(v[t] == tap[j]){
					break;
				}
				tmp++;
			}
			if(tmp > last){
				last = tmp;
				index = j;
			}
		}
		tap[index] = v[i];
		answer++;
	}
	
	cout << answer << endl;
	return 0;
}
