#include <iostream>
#include <algorithm>
using namespace std;
 
int n, a[10100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
 
    int answer = 0;
 
    for (int i = 0; i < n; i++) {
        if (a[i + 1] > a[i + 2]) {
            int t = min(a[i], a[i + 1] - a[i + 2]);
            answer += 5 * t;
            a[i] -= t;
            a[i + 1] -= t;
 
            t = min(a[i], min(a[i + 1], a[i + 2]));
            answer += 7 * t;
            a[i] -= t;
            a[i + 1] -= t;
            a[i + 2] -= t;
        }
        else {
            int t = min(a[i], min(a[i + 1], a[i + 2]));
            answer += 7 * t;
            a[i] -= t;
            a[i + 1] -= t;
            a[i + 2] -= t;
 
            t = min(a[i], a[i + 1]);
            answer += 5 * t;
            a[i] -= t;
            a[i + 1] -= t;
        }
        answer += 3 * a[i];    
    }
 
    printf("%d\n", answer);
    return 0;
}
