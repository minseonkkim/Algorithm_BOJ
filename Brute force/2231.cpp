#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	
	for(int i = 1; i < num; i++){
		sum = i;
		part = i;
		
		while(part){
			sum += part % 10;
			part /= 10;
		}
			
		if(num == sum){
			cout << i << endl;
			return 0;
		}

	}
	cout << "0" << endl;
} 
