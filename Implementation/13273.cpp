#include <iostream>
using namespace std;

string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
string thousands[] = {"", "M", "MM", "MMM"};

int main() {
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		string input, output;
		cin >> input;
		if(input[0] >= '0' && input[0] <= '9'){
			// 아라비아 -> 로마		
			for(int i = 0; i < input.length(); i++){
				int loc = input.length() - i;
				int num = input[i] - '0';
				if(loc == 4){
					for(int j = 0; j < num; j++) output += "M";
				} else if(loc == 3){
					if(num == 0) continue;
					if(num >= 1 && num <= 3){
						for(int j = 0; j < num; j++) output += "C";
					} else if(num == 4) output += "CD";
					else if(num >= 5 && num <= 8){
						output += "D";
						for(int j = 0; j < num - 5; j++) output += "C";
					} else output += "CM";
				} else if(loc == 2){
					if(num == 0) continue;
					if(num >= 1 && num <= 3){
						for(int j = 0; j < num; j++) output += "X";
					} else if(num == 4) output += "XL";
					else if(num >= 5 && num <= 8){
						output += "L";
						for(int j = 0; j < num - 5; j++) output += "X";
					} else output += "XC";
				} else if(loc == 1){
					if(num == 0) continue;
					if(num >= 1 && num <= 3){
						for(int j = 0; j < num; j++) output += "I";
					} else if(num == 4) output += "IV";
					else if(num >= 5 && num <= 8){
						output += "V";
						for(int j = 0; j < num - 5; j++) output += "I";
					} else output += "IX";
				}
			}
		} else{
			// 로마 -> 아라비아
			int start = 0;
			bool hundred = false, ten = false, one = false;
			for(int i = 3; i >= 1; i--){
				if(input.find(thousands[i]) == start){
					output += '0' + i;
					start += thousands[i].length();
					break;
				}
			}
			for(int i = 9; i >= 1; i--){
				if(input.find(hundreds[i], start) == start){
					output += '0' + i;
					start += hundreds[i].length();
					hundred = true;
					break;
				}
			}
			if(!hundred && output.length() != 0) output += '0';
			for(int i = 9; i >= 1; i--){
				if(input.find(tens[i], start) == start){
					output += '0' + i;
					start += tens[i].length();
					ten = true;
					break;
				}
			}
			if(!ten && output.length() != 0) output += '0';
			for(int i = 9; i >= 1; i--){
				if(input.find(ones[i], start) == start){
					output += '0' + i;
					start += ones[i].length();
					one = true;
					break;
				}
			}
			if(!one && output.length() != 0) output += '0';
		}
		cout << output << '\n';
	}
	return 0;
}
