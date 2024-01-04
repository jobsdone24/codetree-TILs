#include<iostream>
#include<climits>
#define MAX_N 100
#define MAX_M 10000
using namespace std;

int weight[MAX_N + 1];
int value[MAX_N + 1];

int dp[MAX_N + 1][MAX_M + 1];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int w, v;
		cin >> w >> v;
		weight[i] = w;
		value[i] = v;
	}

	//값 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = INT_MIN;
		}
	}
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		int w = weight[i];
		int v = value[i];
		for (int j = 0; j <= m; j++) {
			// case 1) i번째 아이템을 선택 해서 j가 되는 경우
			if (j >= w) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + v);
			}

			// case 2) i번째 아이템을 선택하지 않고 j가 되는 경우
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	// 최대값 찾기
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}