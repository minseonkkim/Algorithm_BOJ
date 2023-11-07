#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	stack<pair<int, int>> st;  // 키, 키가 같은 사람이 연속한 수
	long long answer = 0;
	for(int i = 0; i < n; i++){
		int h;
		cin >> h;
		
		// 이전 사람보다 키카 큰 사람이 들어왔다면
		// 이 사람보다 작은 사람들은 더 이상 결과에 영향X
		while(!st.empty() && h > st.top().first){
			answer += st.top().second;
			st.pop();
		}
		
		if(st.empty()){
			st.push({h, 1});
		} else{
			// 바로 앞이 자신과 같다면
			if(st.top().first == h){
				int c = st.top().second;
				st.pop();
				
				// 자신보다 큰 사람이 앞에 있는 경우
				// ex. 4 2 2 2
				if(!st.empty()) answer++;
				
				answer += c;
				st.push({h, c + 1});
				
			} 
			// 바로 앞이 자신보다 크다면
			else{
				answer++;
				st.push({h, 1});
			}
		}
	}
	cout << answer;
	return 0;
}
