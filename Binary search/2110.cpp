#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> house;

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		house.push_back(x);
	}
	sort(house.begin(), house.end());

	int left = 1, right = house[n - 1] - house[0];
	int mid, cnt, last, result;
	while (left <= right) {
		mid = (left + right) / 2;

		cnt = 1;  // 설치한 공유기 개수
		last = house[0];  // 이전에 공유기를 설치한 집
		for (int i = 1; i < n; i++) {
			if (house[i] - last >= mid) {
				cnt++;
				last = house[i];
			}
		}
		if (cnt < c) right = mid - 1;
		else {
			left = mid + 1;
			result = mid;
		}
	}
	cout << result;
}
