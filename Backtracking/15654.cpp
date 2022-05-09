#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
int arr[9];
bool isused[9];

void func(int k){
	if(k == m + 1){
		for(int i = 1; i <= m; i++)
			cout << arr[i] << " ";
		cout << "\n";
	} 
	else{
		for(int i = 1; i <= n; i++){
			if(!isused[i]){
				isused[i] = true;
				arr[k] = v[i];
				func(k + 1);
				isused[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	int x;
	v.push_back(0);
	for(int i = 1; i <= n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	func(1);
	return 0;
}
