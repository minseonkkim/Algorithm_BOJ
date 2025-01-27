#include <iostream>
using namespace std;

int n;
int arr[50];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int cnt = 0;
	while(true){
		bool finish = true;
		for(int i = 0; i < n; i++){
			if(arr[i] % 2 != 0){
				arr[i]--;
				cnt++;
			}
			if(finish && arr[i] != 0) finish = false;
		}
		if(finish) break;
		
		finish = true;
		for(int i = 0; i < n; i++){
			arr[i] /= 2;
			if(finish && arr[i] != 0) finish = false;
		}
		cnt++;
		if(finish) break;
	}
	cout << cnt;
	return 0;
}
