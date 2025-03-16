#include <iostream>
#include <vector>
using namespace std;

int s, c;
vector<long long> len;

int main() {
	cin >> s >> c;
	long long sum = 0;
	for(int i = 0; i < s; i++){
		long long x;
		cin >> x;
		len.push_back(x);
		sum += x;
	}
	
	long long l = 1, r = 1000000000, result = 0;
	while(l <= r){
		long long mid = (l + r) / 2;
		long long cnt = 0;
		for(int i = 0; i < len.size(); i++){
			cnt += len[i] / mid;
		}
		if(cnt < c) r = mid - 1;
		else{
			l = mid + 1;
			result = mid;
		}
	}
    long long answer = sum - result * c;
	cout << answer;
	return 0;
}
