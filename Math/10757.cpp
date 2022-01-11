#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string a, b, tmp;
	cin >> a >> b;
	
	int num1[10001], num2[10001];
	int sum;
	vector<int> v;
	
	// 더 긴 문자열을 a로 저장
	if(a.size() < b.size()){
		tmp = a;
		a = b;
		b = tmp;
	}
	
	for(int i = 0; i < a.size(); i++)
		num1[i + 1] = a[i] - '0';
		
	for(int i = 0; i < b.size(); i++)
		num2[i + 1 + a.size() - b.size()] = b[i] - '0';
		
	for(int i = a.size(); i > 0; i--){
		sum = num1[i] + num2[i];
		if(sum >= 10){
			num1[i - 1]++;
			sum -= 10;
		}
		v.push_back(sum);
	}
	
	// 맨 앞자리 수 출력
	if(num1[0] != 0) cout << 1;
	
	for(int i = v.size() - 1; i >= 0; i--){
		cout << v[i];
	}
}
