#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;
    
    priority_queue<int> q;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (q.empty()) {
                cout << "0\n";
            }
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else {
            q.push(x);
        }
    }
    return 0;
}
