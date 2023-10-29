#include <iostream>
#include <vector>
using namespace std;

struct Ingredient{
	int p, f, s, v, c;
};

int n, mp, mf, ms, mv;
vector<Ingredient> v;
vector<int> tmp;
vector<int> ans;
int answer = 987654321;

void dfs(int idx, int sp, int sf, int ss, int sv, int sc){
	if(sp >= mp && sf >= mf && ss >= ms && sv >= mv){
		if(sc < answer || (sc == answer && ans > tmp)) {
			answer = sc;
			ans = tmp;
		} 
		return;
	}
	if(idx == n + 1) return;
	
	dfs(idx + 1, sp, sf, ss, sv, sc);
	
	tmp.push_back(idx);
	dfs(idx + 1, sp + v[idx].p, sf + v[idx].f, ss + v[idx].s, sv + v[idx].v, sc + v[idx].c);
	tmp.pop_back();
}

int main() {
	cin >> n >> mp >> mf >> ms >> mv;
	v.push_back({0, 0, 0, 0, 0});
	for(int i = 0; i < n; i++){
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		v.push_back({a, b, c, d, e});
	}
	dfs(1, 0, 0, 0, 0, 0);
	if(answer == 987654321) cout << -1;
	else {
		cout << answer << endl;
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i] << " ";
		}
	}
	
	return 0;
}
