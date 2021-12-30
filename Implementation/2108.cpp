#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, num, sum = 0;
	cin >> n;
 
	int number[8001] = {0, };
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin >> num;
		v.push_back(num);
		sum += num;
		number[num + 4000]++;
	}
 
	cout << round((float)sum / n) << endl;
 
	sort(v.begin(), v.end());
	cout << v[n / 2] << endl;
 
	bool isFirst = false;
	int most_v, most = -9999;
	for(int i = 0; i < 8001; i++){
		if(number[i] == 0) continue;
		if(number[i] == most){
			if(isFirst){
				most_v = i - 4000;
				isFirst = false;
			}
		}
		if(number[i] > most){
			most = number[i];
			most_v = i - 4000;
			isFirst = true;
		}
	}
	cout << most_v << endl;
 
	cout << v[n - 1] - v[0] << endl;
	return 0;
}
