#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int parent[101];
vector<pair<double, double>> star;
vector<pair<double, pair<int, int>>> v;

int getParent(int a){
	if(a == parent[a]) return a;
	return getParent(parent[a]);
}

void unionParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	parent[b] = a;
}

bool findParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a == b) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(2);
	
	cin >> n;
	
	for(int i = 0; i < n; i++){ 
		double a, b;
		cin >> a >> b;
		star.push_back({a, b});
	}
	
	for(int i = 0; i < n; i++){
		double a = star[i].first;
		double b = star[i].second;
		for(int j = i + 1; j < n; j++){
			double aa = star[j].first;
			double bb = star[j].second;
			
			double t = sqrt((aa - a) * (aa - a) + (bb - b) * (bb - b));
			v.push_back({t, {i, j}});
		}
	}
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++) 
		parent[i] = i;
	
	double answer = 0;
	for(int i = 0; i < v.size(); i++){
		if(!findParent(v[i].second.first, v[i].second.second)){
			answer += v[i].first;
			unionParent(v[i].second.first, v[i].second.second);
		}
	}
	
	cout << answer << endl;
	return 0;
}
