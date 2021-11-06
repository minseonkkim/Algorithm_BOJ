#include <iostream>
using namespace std;

pair<int, int> edge[26];

void pre(char cur) {
    if (cur == '.') return;

    cout << cur;
    pre(edge[cur - 'A'].first);
    pre(edge[cur - 'A'].second);
}

void in(char cur) {
    if (cur == '.') return;

    in(edge[cur - 'A'].first);
    cout << cur;
    in(edge[cur - 'A'].second);
}

void post(char cur) {
    if (cur == '.') return;

    post(edge[cur - 'A'].first);
    post(edge[cur - 'A'].second);
    cout << cur;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char node, left, right;
        cin >> node >> left >> right;
        edge[node - 'A'] = { left, right };
    }

    pre('A');
    cout << '\n';
    in('A');
    cout << '\n';
    post('A');
    return 0;
}
