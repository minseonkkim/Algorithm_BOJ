#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string dp[10001];

string big_num_sum(string a, string b){
	int sum;
	string s;
	vector<int> v, num1, num2;
	
	if(a.size() < b.size()){
		string tmp = a;
		a = b;
		b = tmp;
	}
	
	num1.push_back(0);
	num2.push_back(0);
	
	for (int i = 0; i < a.size() - b.size(); i++)
		num2.push_back(0);
		
	for(int i = 0; i < a.size(); i++)
		num1.push_back(a[i] - '0');
		
	for(int i = 0; i < b.size(); i++)
		num2.push_back(b[i] - '0');
		
	for(int i = a.size(); i > 0; i--){
		sum = num1[i] + num2[i];
		if(sum >= 10){
			num1[i - 1]++;
			sum -= 10;
		}
		v.push_back(sum);
	}

	if(num1.front() != 0) s.push_back('1');
	
	for(int i = v.size() - 1; i >= 0; i--){
		s.push_back(v[i] + 48);
	}
	
	return s;
}

int main() {
	cin >> n;
	
	dp[0] = '0'; dp[1] = '1';
	
	for(int i = 2; i <= n; i++){
		dp[i] = big_num_sum(dp[i - 1], dp[i - 2]);
	}
	
	cout << dp[n];
	return 0;
}
