#include<iostream>
#include<climits>

#define MAX_N 100
#define MAX_T 100000
using namespace std;

int energy[MAX_N + 1];
int t[MAX_N + 1];
int totaltime = 0;

int dp[MAX_N + 1][MAX_T+1]; // dp[i][j] -> i번째 원소까지 생각했을 때 시간의 총합이 j일 때 최대 경험치
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> energy[i] >> t[i];
		totaltime += t[i];
	}

	//초기값 설정
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= totaltime; j++) {
			dp[i][j] = INT_MIN;
		}
	}
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j<=totaltime; j++) {
			// case1) i번째 quest를 하는 경우
			int time = t[i];
			if (j >= time) {
				dp[i][j] = max(dp[i][j], dp[i-1][j - time] + energy[i]);
			}
			dp[i][j] = max(dp[i][j],dp[i - 1][j]);
		}
	}
	for (int i = 1; i <= totaltime; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}