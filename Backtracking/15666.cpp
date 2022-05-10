#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
int arr[9];

void func(int s, int k){
	int last = 0;
	if(k == m + 1){
		for(int i = 1; i <= m; i++)
			cout << arr[i] << " ";
		cout << "\n";
	} 
	else{
		for(int i = s; i <= n; i++){
			if(v[i] != last){
				arr[k] = v[i];
				last = arr[k];
				func(i, k + 1);
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
	func(1, 1);
	return 0;
}
