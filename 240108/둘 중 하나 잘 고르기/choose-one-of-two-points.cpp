#include<iostream>
#include<climits>
#define MAX_N 100
using namespace std;

int dp[MAX_N * 2 + 1][MAX_N+1]; // dp[i][j] -> i번째 까지 고려했을 때 빨간색을 j개 뽑았을 경우 dp의 최대값
int card[MAX_N * 2 + 1][2];

int main() {
	int N;
	cin >> N;
	
	for (int i = 1; i <= 2*N; i++) {
		cin >> card[i][0] >> card[i][1]; // 0 -> RED, 1 -> BLUE
	}
	
	// 초기화
	for (int i = 0; i <= 2 * N; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i][j] = INT_MIN;
		}
	}
	dp[0][0] = 0;
	dp[1][0] = card[1][1];
	dp[1][1] = card[1][0];

	// 점화식 진행
	for (int i = 2; i <= 2 * N; i++) {
		for (int j = 0; j <= N; j++) {
			// case1) 빨간색을 선택하는 경우
			if (j - 1 >= 0) {
				dp[i][j] = max(dp[i][j], dp[i-1][j - 1] + card[i][0]);
			}
			// case2) 파란색을 선택하는 경우
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + card[i][1]);
		}
	}
	cout << dp[2 * N][N];
}