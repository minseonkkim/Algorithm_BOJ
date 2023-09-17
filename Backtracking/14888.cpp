#include <iostream>
using namespace std;

int n;
int operands[11];
int operators[4];
int min_result = 1000000001;
int max_result = -1000000001;

void getanswer(int result, int idx){
	if(idx == n){
		if(result < min_result) min_result = result;
		if(result > max_result) max_result = result;
		return;
	} else{
		for(int i = 0; i < 4; i++){
			if(operators[i] > 0){
				operators[i]--;
				if(i == 0) getanswer(result + operands[idx], idx + 1);
				else if(i == 1) getanswer(result - operands[idx], idx + 1);
				else if(i == 2) getanswer(result * operands[idx], idx + 1);
				else if(i == 3) getanswer(result / operands[idx], idx + 1);
				operators[i]++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> operands[i];
	}
	for(int i = 0; i < 4; i++){
		cin >> operators[i];
	}
	
	getanswer(operands[0], 1);
	
	cout << max_result << endl;
	cout << min_result << endl;
	return 0;
}
