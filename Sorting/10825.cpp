#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
	string name;
	int kor, eng, math;
};

vector<Student> students;

bool cmp(Student a, Student b){
	if(a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
	if(a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
	if(a.kor == b.kor) return a.eng < b.eng;
	return a.kor > b.kor;
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string n;
		int k, e, m;
		cin >> n >> k >> e >> m;
		students.push_back({n, k, e, m});
	}
	sort(students.begin(), students.end(), cmp);
	for(int i = 0; i < n; i++){
		cout << students[i].name << '\n';
	}
	return 0;
}
