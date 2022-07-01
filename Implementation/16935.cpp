#include <iostream>
using namespace std;

int n, m, r;
int arr[100][100];
int tmp[100][100];

void one(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			tmp[i][j] = arr[n - 1 - i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			arr[i][j] = tmp[i][j];
		}
	}
}

void two(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			tmp[i][j] = arr[i][m - 1 - j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			arr[i][j] = tmp[i][j];
		}
	}
}

void three(){
	int t = n;
	n = m;
	m = t;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			tmp[i][j] = arr[m - 1 - j][i];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			arr[i][j] = tmp[i][j];
		}
	}
}

void four(){
	int t = n;
	n = m;
	m = t;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			tmp[i][j] = arr[j][n - 1 - i];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			arr[i][j] = tmp[i][j];
		}
	}
}

void five(){
	// tmp에 1 저장
	for(int i = 0; i < n / 2; i++){
		for(int j = 0; j < m / 2; j++){
			tmp[i][j] = arr[i][j];
		}
	}
	// 4 -> 1
	for(int i = 0; i < n / 2; i++){
		for(int j = 0; j < m / 2; j++){
			arr[i][j] = arr[i + n / 2][j];
		}
	}
	// 3 -> 4
	for(int i = n / 2; i < n; i++){
		for(int j = 0; j < m / 2; j++){
			arr[i][j] = arr[i][j + m / 2];
		}
	}
	// 2 -> 3
	for(int i = n / 2; i < n; i++){
		for(int j = m / 2; j < m; j++){
			arr[i][j] = arr[i - n / 2][j];
		}
	}
	// tmp -> 2
	for(int i = 0; i < n / 2; i++){
		for(int j = m / 2; j < m; j++){
			arr[i][j] = tmp[i][j - m / 2];
		}
	}
}

void six(){
	// tmp에 1 저장
	for(int i = 0; i < n / 2; i++){
		for(int j = 0; j < m / 2; j++){
			tmp[i][j] = arr[i][j];
		}
	}
	// 2 -> 1
	for(int i = 0; i < n / 2; i++){
		for(int j = 0; j < m / 2; j++){
			arr[i][j] = arr[i][j + m / 2];
		}
	}
	// 3 -> 2
	for(int i = 0; i < n / 2; i++){
		for(int j = m / 2; j < m; j++){
			arr[i][j] = arr[i + n / 2][j];
		}
	}
	// 4 -> 3
	for(int i = n / 2; i < n; i++){
		for(int j = m / 2; j < m; j++){
			arr[i][j] = arr[i][j - m / 2];
		}
	}
	// tmp -> 4
	for(int i = n / 2; i < n; i++){
		for(int j = 0; j < m / 2; j++){
			arr[i][j] = tmp[i - n / 2][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> r;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 0; i < r; i++){
		int x;
		cin >> x;
		if(x == 1) one();
		else if(x == 2) two();
		else if(x == 3) three();
		else if(x == 4) four();
		else if(x == 5) five();
		else six();
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
