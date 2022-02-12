#include <iostream>
#include <cmath>
using namespace std;
 
int n, r, c;
int result;
 
void recursion(int x, int y, int len) {
   if (y == r && x == c) {
      cout << result << endl;
      return;
   }
   if (len == 1) { 
      result++; return;
   }
   if (!(y <= r && r < y + len && x <= c && c < x + len)) { //
      result += len * len;
      return;
   }
   recursion(x, y, len / 2);     
   recursion(x + len / 2, y, len / 2);          
   recursion(x, y + len / 2, len / 2);           
   recursion(x + len / 2, y + len / 2, len / 2); 
}
 
int main() {
   cin >> n;           
   cin >> r;           
   cin >> c;           
   recursion(0, 0, pow(2, n));      
 
   return 0;
}
