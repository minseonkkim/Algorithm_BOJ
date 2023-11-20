#include <iostream>
using namespace std;

int paper[2200][2200];
int sum1, sum2, sum3;

void divide(int x, int y, int size){
	int num = paper[x][y];
	bool same = true;
	for(int i = x; i < x + size; i++){
		for(int j = y; j < y + size; j++){
			if(paper[i][j] != num){
				same = false;
			}
		}
	}
	if(same){
		if(num == -1) sum1++;
		else if(num == 0) sum2++;
		else if(num == 1) sum3++;
		return;
	}
	
	divide(x, y, size / 3);
	divide(x, y + size / 3, size / 3);
	divide(x, y + size / 3 * 2, size / 3);
	divide(x + size / 3, y, size / 3);
	divide(x + size / 3, y + size / 3, size / 3);
	divide(x + size / 3, y + size / 3 * 2, size / 3);
	divide(x + size / 3 * 2, y, size / 3);
	divide(x + size / 3 * 2, y + size / 3, size / 3);
	divide(x + size / 3 * 2, y + size / 3 * 2, size / 3);
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> paper[i][j];
		}
	}
	divide(0, 0, n);
	cout << sum1 << endl;
	cout << sum2 << endl;
	cout << sum3 << endl;
	return 0;
}
