#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
	return a > b;
}

int main() {
	int k, n;
	cin >> k;
	
	for(int i = 0; i < k; i++){
		int maxgap = -1;
		cin >> n;
		vector<int> v(n);
		for(int j = 0; j < n; j++){
			cin >> v[j];
		}
		
		sort(v.begin(), v.end(), compare);
		
		for(int j = 1; j < n; j++){
			if(maxgap < v[j - 1] - v[j]){
				maxgap = v[j - 1] - v[j];
			}
		}
		
		cout << "Class " << i + 1 << endl;
		cout << "Max " << v.front() << ", Min " << v.back() << ", Largest gap " << maxgap << endl; 
		
		v.clear();
	}
	return 0;
}
