#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> burger, side, drink;
int b, c, d, totalprice, disprice;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> b >> c >> d;
    int mincnt = min(min(b, c), d);

    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        burger.push_back(x);
        totalprice += x;
    }
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        side.push_back(x);
        totalprice += x;
    }
    for (int i = 0; i < d; i++) {
        int x;
        cin >> x;
        drink.push_back(x);
        totalprice += x;
    }

    sort(burger.begin(), burger.end(), greater<>());
    sort(side.begin(), side.end(), greater<>());
    sort(drink.begin(), drink.end(), greater<>());

    for (int i = 0; i < mincnt; i++) {
        disprice += burger[i] * 0.9;
        disprice += side[i] * 0.9;
        disprice += drink[i] * 0.9;
    }
    for (int i = mincnt; i < b; i++) {
        disprice += burger[i];
    }
    for (int i = mincnt; i < c; i++) {
        disprice += side[i];
    }
    for (int i = mincnt; i < d; i++) {
        disprice += drink[i];
    }

    cout << totalprice << endl;
    cout << disprice << endl;

    return 0;
}
