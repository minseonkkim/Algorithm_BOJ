#include <iostream>
#include <cstring>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
    
	char a[100001]; 
	char b[100001];
	cin >> a >> b;
	
	// A & B
	for(int i = 0; i < strlen(a); i++){
		if(a[i] == '1' && b[i] == '1')
			cout << '1';
		else cout << '0';
	}
	cout << '\n';
	
	// A | B
	for(int i = 0; i < strlen(a); i++){
		if(a[i] == '1' || b[i] == '1')
			cout << '1';
		else cout << '0';
	}
	cout << '\n';
	
	// A ^ B
	for(int i = 0; i < strlen(a); i++){
		if(a[i] != b[i])
			cout << '1';
		else cout << '0';
	}
	cout << '\n';
	
	// ~A
	for(int i = 0; i < strlen(a); i++){
		if(a[i] == '0')
			cout << '1';
		else cout << '0';
	}
	cout << '\n';
	
	// ~B
	for(int i = 0; i < strlen(a); i++){
		if(b[i] == '0')
			cout << '1';
		else cout << '0';
	}
	return 0;
}
