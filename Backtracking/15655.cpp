#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
bool isUsed[8];
int ans[8];

void getAnswer(int num, int idx){
	if(idx == m){
		for(int i = 0; i < m; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	} else{
		for(int i = num; i < n; i++){
			if(!isUsed[i]){
				isUsed[i] = true;
				ans[idx] = arr[i];
				getAnswer(i + 1, idx + 1);
				isUsed[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	getAnswer(0, 0);
	return 0;
}
