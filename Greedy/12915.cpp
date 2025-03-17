#include <iostream>
using namespace std;

int level[6];

int main() {
	for(int i = 0; i < 5; i++){
		cin >> level[i];
	}
	int answer = 0;
	while(true){
		if(level[0] > 0) level[0]--;
		else{
			if(level[1] > 0) level[1]--;
			else break;
		}
		
		if(level[2] > 0) level[2]--;
		else{
			if(level[1] > 0 || level[3] > 0){
				if(level[1] >= level[3]) level[1]--;
			    else level[3]--;
			} 
			else break;
		}
		
		if(level[4] > 0) level[4]--;
		else{
			if(level[3] > 0) level[3]--;
			else break;
		}
		answer++;
	}
	cout << answer;
	return 0;
}
