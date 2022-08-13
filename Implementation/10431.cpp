#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int p;
	cin >> p;
	
	for(int i = 0; i < p; i++){
		int t;
		cin >> t;
		
		int height[21];
		int step = 0;
		for(int j = 0; j < 20; j++) cin >> height[j];
		for(int j = 1; j < 20; j++){
			for(int k = 0; k < j; k++){
				if(height[k] > height[j]) step++;
			}
		}
		
		cout << t << " " << step << endl;
	}
	return 0;
}
