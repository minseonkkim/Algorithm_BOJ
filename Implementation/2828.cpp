#include <iostream>
using namespace std;

int main() {
	int n, m, j;
	cin >> n >> m >> j;
	int left = 1, right = left + m - 1;
	int answer = 0;
	for(int i = 0; i < j; i++){
		int fall;
		cin >> fall;
		
		if(fall >= left && fall <= right) continue;
		
		if(right < fall){
			int offset = fall - right;
			left += offset;
			right += offset;
			answer += offset;
		} else if(left > fall){
			int offset = left - fall;
			left -= offset;
			right -= offset;
			answer += offset;
		}
	}
	cout << answer;
	return 0;
}
