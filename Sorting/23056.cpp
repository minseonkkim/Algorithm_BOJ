#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
	int team; // 청팀: 1, 백팀: 2
	int clas;
	string name;
};

bool cmp(Student a, Student b){
	if(a.clas == b.clas){
		if(a.name.length() == b.name.length()) return a.name < b.name;
		return a.name.length() < b.name.length();
	}
	if(a.team == b.team) return a.clas < b.clas;
	return a.team < b.team;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<Student> students;
	int cnt[11] = {0, };
	while(true){
		int cls; string nme;
		cin >> cls >> nme;
		if(cls == 0) break;
		
		int tm;
		if(cls % 2 == 0) tm = 2;
		else tm = 1;
		if(cnt[cls] < m) {
			students.push_back({tm, cls, nme});
			cnt[cls]++;
		}
	}
	sort(students.begin(), students.end(), cmp);
	for(int i = 0; i < students.size(); i++){
		cout << students[i].clas << " " << students[i].name << '\n';
	}
	return 0;
}
