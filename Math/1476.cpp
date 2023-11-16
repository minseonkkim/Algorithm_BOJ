#include<iostream>
using namespace std;

int main()
{
	int e, s, m;
    cin >> e >> s >> m;
        
    int num = 1;
    while(true){
        if((num - e) % 15 == 0 && (num - s) % 28 == 0 && (num - m) % 19 == 0) break;
    	num++;
    }
	cout << num << endl;

	return 0;
}
