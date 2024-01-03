#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int map[103][103] = { 0 };
	pair<int, int> dp[103][103] = { {} };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	//초기값 입력
	dp[0][0] = {map[0][0],map[0][0]};
	
	for (int i = 1; i < N; i++) {
		//최대값 초기화 하기
		dp[0][i].first = max(dp[0][i - 1].first, map[0][i]);
		//최소값
		dp[0][i].second = min(dp[0][i - 1].second, map[0][i]);

		//최대값 초기화 하기
		dp[i][0].first = max(dp[i-1][0].first, map[i][0]);
		//최소값
		dp[i][0].second = min(dp[i-1][0].second, map[i][0]);
	}
	
	//점화식 적용
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			// case1) 위에서 오는 경우
			int ub = dp[i - 1][j].first;
			int us = dp[i - 1][j].second;
			
			//새로운 위치에서 다시 갱신해주기
			if (ub < map[i][j]) ub = map[i][j];
			if (us > map[i][j]) us = map[i][j];
			int ugap = abs(ub - us);

			// case2) 왼쪽에서 오는 경우
			int lb = dp[i][j-1].first;
			int ls = dp[i][j-1].second;
			
			//새로운 위치에서 다시 갱신해주기
			if (lb < map[i][j]) lb = map[i][j];
			if (ls > map[i][j]) ls = map[i][j];
			int lgap = abs(lb - ls);

			if (ugap <= lgap) {
				dp[i][j].first = ub;
				dp[i][j].second = us;
			}
			else {
				dp[i][j].first = lb;
				dp[i][j].second = ls;
			}
		}
	}
	cout << dp[N - 1][N - 1].first - dp[N - 1][N - 1].second;
}