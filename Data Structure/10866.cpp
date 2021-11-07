#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    int n, x;
    string str;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "push_front") {
            cin >> x;
            dq.push_front(x);
        }
        else if (str == "push_back") {
            cin >> x;
            dq.push_back(x);
        }
        else if (str == "pop_front") {
            if (dq.empty())
                cout << "-1" << endl;
            else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if (str == "pop_back") {
            if (dq.empty())
                cout << "-1" << endl;
            else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
        else if (str == "size") {
            cout << dq.size() << endl;
        }
        else if (str == "empty") {
            if (dq.empty())
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
        else if (str == "front") {
            if (dq.empty())
                cout << "-1" << endl;
            else
                cout << dq.front() << endl;
        }
        else if (str == "back") {
            if (dq.empty())
                cout << "-1" << endl;
            else
                cout << dq.back() << endl;
        }
    }
    return 0;
}
