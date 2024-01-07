#include<iostream>
#include<climits>
#define MAX_N 500
#define MIN_E -50001
using namespace std;


int elements[MAX_N + 1];
int dp[MAX_N + 1][(MAX_N + 1) / 2][2]; //dp[i][j][k] 마지막으로 i까지 고려했을 때, 지금 k구간 만들고 있으면 0, 구간 만들고있지 않으면 1일때 구간이 j일 때 최대값
int m;

int main() {
	int n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> elements[i];

	//초기값 처리
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int p = 0; p < 2; p++) {
				dp[i][j][p] = MIN_E;
			}
		}
	}
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
	dp[1][1][1] = elements[1];
	dp[1][0][0] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			//해당 원소를 선택하는 경우
			//쭉 수열이 이어질 경우, 새로 시작할 경우
			dp[i][j][1] = max(dp[i - 1][j][1] + elements[i], dp[i-1][j-1][0] + elements[i]);

			//선택하지 않는 경우
			dp[i][j][0] = max(dp[i-1][j][1], dp[i - 1][j][0]);		
		}
	}
	
	int ans = max(dp[n][m][0], dp[n][m][1]);
	cout << ans;

}