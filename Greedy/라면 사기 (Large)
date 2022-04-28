#include <iostream>
#include <algorithm>
using namespace std;
 
long long n, b, c, a[1000003];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> b >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    long long answer = 0;
	 if (b <= c) {
        for (int i = 0; i < n; i++) {
            answer += b * a[i];
        }
    } else{
    	for (int i = 0; i < n; i++) {
            if (a[i + 1] > a[i + 2]) {
                long long t = min(a[i], a[i + 1] - a[i + 2]);
                answer += (b + c) * t;
                a[i] -= t;
                a[i + 1] -= t;
 
                t = min(a[i], min(a[i + 1], a[i + 2]));
                answer += (b + 2 * c) * t;
                a[i] -= t;
                a[i + 1] -= t;
                a[i + 2] -= t;
            }
            else {
                long long t = min(a[i], min(a[i + 1], a[i + 2]));
                answer += (b + 2 * c) * t;
                a[i] -= t;
                a[i + 1] -= t;
                a[i + 2] -= t;
     
                t = min(a[i], a[i + 1]);
                answer += (b + c) * t;
                a[i] -= t;
                a[i + 1] -= t;
            }
            answer += b * a[i]; 
        }
    }
 
    cout << answer << endl;
    return 0;
}
