#include<iostream>
#include<climits>
#define MAX_N 500
#define MAX_M 100
using namespace std;

int dp[MAX_N + 1][MAX_M + 1][5]; 
// dp[i][j][n] i번째 수열을 볼때 다릇 횟수가 j일때 n을 선택한 경우 가장 높은 유사도

int main() {
	int N, M;
	cin >> N >> M;
	int original[MAX_N + 1] = { 0 };

	//입력
	for (int i = 1; i <= N; i++) {
		cin >> original[i];
	}

	//값 초기화
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			for (int k = 0; k <= 4; k++) {
				dp[i][j][k] = INT_MIN;
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (original[1] == i) dp[1][0][i] = 1;
		else dp[1][0][i] = 0;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i <= j) continue;
			for (int k = 1; k <= 4; k++) {
				int plus = 0;
				if (original[i] == k) plus = 1;

				for (int q = 1; q <= 4; q++) {
					// 지금 k를 선택했을 때 전에 선택한 것이 q일때 고려하기
					// case1) 이전과 같은 것을 선택한 경우
					if (k == q) {
						if (dp[i - 1][j][k] == INT_MIN) continue;
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + plus);
					}
					// case2) 이전과 다른 것을 선택한 경우 
					else {
						if (dp[i - 1][j - 1][q] == INT_MIN) continue;
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][q] + plus);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j <= M; j++) {
			ans = max(ans, dp[N][j][i]);
		}
	}
	cout << ans;
}