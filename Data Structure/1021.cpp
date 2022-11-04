#include <iostream>
#include <deque>
using namespace std;
 
int main(){
	int n, m, num, index, count = 0;
	deque<int> d;
 
	cin >> n >> m;
 
	for (int i = 1; i <= n; ++i) {
		d.push_back(i);
	}
 
	while (m--){
		cin >> num;
 
		for (int i = 0; i < d.size(); ++i) {
			if (d[i] == num) {
				index = i;
				break;
			}
		}
 
		if (index < d.size() - index) {
			while (1) {
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				++count;
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else {
			while (1) {
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				++count;
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}
	cout << count << endl;
	
	return 0;
}
