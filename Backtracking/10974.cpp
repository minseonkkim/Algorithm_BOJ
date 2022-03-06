// sol1
#include <iostream>
using namespace std;

int n;
int arr[9];
bool isused[9];

void func(int k) {
	if(k == n + 1) {
		for(int i = 1; i <= n; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	else {
		for(int i = 1; i <= n; i++){
			if(!isused[i]) {
				isused[i] = true;
				arr[k] = i;
				func(k + 1);
				isused[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	func(1);
	return 0;
}


/* sol2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		v.push_back(i + 1);
	}
	
	do{
		for(int i = 0; i < n; i++){
			cout << v[i] << " ";
		}
		cout << '\n';
	} while(next_permutation(v.begin(), v.end()));
	return 0;
}
*/
