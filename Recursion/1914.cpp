#include <iostream>
#include <cmath>
#include <string>
using namespace std;
 
void move(int no, int x, int y){
	if(no > 1)
		move(no - 1, x, 6 - x - y); 
	cout << x << " " << y << '\n';
	if(no > 1)
		move(no - 1, 6 - x - y, y);
}
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
    
	int n;
	cin >> n;
	
	string a = to_string(pow(2, n));
	
	int x = a.find('.');     // pow 함수 결과가 실수형이기에 소수점 찾기
  a = a.substr(0, x);      // 소수점 앞자리만 나오게 하기
	a[a.length() - 1] -= 1;  // string a에 대한 마지막 위치의 인덱스 값에 -1
  
	cout << a << '\n';
	
	if(n <= 20)
		move(n, 1, 3);
	return 0;
}
