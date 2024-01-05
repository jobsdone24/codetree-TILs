#include<iostream>
#include<climits>
#define MAX_N 100
#define MAX_M 10000
using namespace std;

int l[MAX_N + 1];
int dp[MAX_N + 1][MAX_N+1];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int value;
		cin >> value;
		l[i] = value;
	}

	//값 초기화
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = INT_MIN;
		}
	}

	for (int i = 1; i <= n; i++) {
		int v = l[i];
		for (int j = 0; j <= n; j++) {
			// case 1) i번째 아이템을 선택 해서 j가 되는 경우
			if (j >= i) {
				dp[i][j] = max(max(dp[i-1][j], dp[i - 1][j - i] + v), dp[i][j-i]+v);
			}
			// case 2) i번째 아이템을 선택하지 않고 j가 되는 경우
			else dp[i][j] = dp[i - 1][j];
		}
	}
    


	// 최대값 찾기
	cout << dp[n][n];
}