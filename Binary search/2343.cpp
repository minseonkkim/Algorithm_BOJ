#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int N, M;
	cin >> N >> M;
	vector<int> v;
	long long sum = 0;
    long long max = 0;
	for(int i = 0; i < N; i++){
		int x;
		cin >> x;
		v.push_back(x);
        if(x > max) max = x;
		sum += x;
	}
	
	long long l = max, r = sum, answer = 0;
	while(l <= r){
		long long mid = (l + r) / 2;
		
		int cnt = 0, idx = 0;
		while(idx < N){
			cnt++;
			long long onesum = 0;
			while(idx < N && onesum + v[idx] <= mid){
				onesum += v[idx];
				idx++;
			}
		}
		
		if(cnt <= M){
			answer = mid;
			r = mid - 1;
		} else{
			l = mid + 1;
		}
	}
	cout << answer;
	return 0;
}
