#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1000001];
vector<int> seq;

void binary_search(int num){
	int low = 0, high = seq.size() - 1, mid;
	int ret = 1000000007;
	while(low <= high){
		mid = (low + high) / 2;
		int midnum = seq[mid];
		if(midnum >= num){
			if(ret > mid) ret = mid;
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	seq[ret] = num;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
		
	seq.push_back(arr[0]);
	for(int i = 1; i < n; i++){
		if(seq.back() < arr[i]){
			seq.push_back(arr[i]);
		} else{
			binary_search(arr[i]);
		}
	}
	cout << seq.size();
	return 0;
}
