#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long n, m;
vector<unsigned long long> audit_time;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		audit_time.push_back(t);
	}
    
    sort(audit_time.begin(), audit_time.end());
	
	unsigned long long l = 1, r = audit_time[n - 1] * m, answer = 0;
	while(l <= r){
		unsigned long long mid = (l + r) / 2;
		
		long long sum = 0;
		for(int i = 0; i < n; i++){
			sum += mid / audit_time[i];
		}
		
		if(sum >= m){
			r = mid - 1;
			answer = mid;
		} else l = mid + 1;
	}
	cout << answer;
	return 0;
}
