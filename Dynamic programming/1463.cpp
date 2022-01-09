#include <iostream> 
using namespace std; 

int min(int a, int b) { 
    return a < b ? a : b; 
} 

int main() { 
    int dp[1000001]; 
    dp[0] = dp[1] = 0; 
    
    int input; 
    cin >> input; 
    for (int i = 2; i <= input; ++i) { 
        dp[i] = dp[i - 1] + 1; 
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1); 
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1); 
    } 
    cout << dp[input] << endl; 
}
