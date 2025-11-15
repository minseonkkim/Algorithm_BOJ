#include <iostream>
#include <algorithm>
using namespace std;

int calorie[5001];
int price[5001];
int dp[10002];

int main() {
	int n; double m;
	while(true){
		cin >> n >> m;
		if(n == 0 && m == 0.0) break;
		int money = (int)(m * 100 + 0.5);
		
		for(int i = 1; i <= n; i++){
			int c; double p;
			cin >> c >> p;
			calorie[i] = c;
			price[i] = p * 100 + 0.5;
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = price[i]; j <= money; j++){
				dp[j] = max(dp[j], dp[j - price[i]] + calorie[i]);
			}
		}
		
		cout << dp[money] << '\n';
		
		// 초기화
		for(int i = 1; i <= n; i++){
			calorie[i] = 0;
			price[i] = 0.00;
		}
		for(int i = 1; i <= money; i++){
			dp[i] = 0;
		}
	}
	return 0;
}
