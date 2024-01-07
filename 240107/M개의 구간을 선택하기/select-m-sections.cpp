#include<iostream>
#include<climits>
#define MAX_N 500
#define MIN_E -50001
using namespace std;


int elements[MAX_N + 1];
int dp[MAX_N + 1][(MAX_N + 1) / 2]; //dp[i][j] 마지막으로 i를 선택했을 때, 구간이 j일 때 최대값
int m;

int main() {
	int n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> elements[i];

	//초기값 처리
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = MIN_E;
		}
	}
	dp[0][0] = 0;
	dp[1][1] = elements[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= (i + 1) / 2; j++) {
			//해당 원소를 선택하는 경우
			dp[i][j] = max(dp[i-1][j] + elements[i], dp[i - 2][j - 1] + elements[i]);

		}
	}


	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i][m]);
	}
	cout << ans;
}