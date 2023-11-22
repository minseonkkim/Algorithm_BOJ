#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, s;
vector<int> v;
 
int main() {
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	int start = 0, end = 0, sum = v[0], minlen = 987654321;
	while(start <= end && end <= n - 1){
		if(sum < s){
			end++;
			sum += v[end];
		} else{
			minlen = min(minlen, end - start + 1);
			sum -= v[start];
			start++;
		}
	}
	if(minlen == 987654321) cout << 0;
	else cout << minlen;
 	return 0;
}
