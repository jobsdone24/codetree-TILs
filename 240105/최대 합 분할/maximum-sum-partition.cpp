#include<iostream>
#include<climits>
#define MAX_N 100
#define MAX_M 100000
#define OFFSET 100000
using namespace std;

int arr[MAX_N + 1];
int dp[MAX_N + 1][MAX_M + 1 + OFFSET]; // dp[i][j] -> i번째 까지 고려했을 때 SUM A - SUM B가 j가 될때 SUM A의 최대값
int n;
int m;

void Initialize() {
	for (int i = 0; i <= n; i++) {
		for (int j = -m; j <= m; j++) {
			dp[i][j+OFFSET] = INT_MIN;
		}
	}

	dp[0][0+OFFSET] = 0;
}

// A를 새로 갱신 하는 것 -> A의 합만 알면 되기 때문에

void Update(int i, int j, int prev_i, int prev_j, int val) {
	if (prev_j<-m || prev_j>m || dp[prev_i][prev_j+OFFSET] == INT_MIN) return;
	dp[i][j + OFFSET] = max(dp[i][j + OFFSET], dp[prev_i][prev_j + OFFSET] + val);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		m += arr[i];
	}

	Initialize();

	for (int i = 1; i <= n; i++) {
		// Sum A - Sum B는 -m 부터 m 까지 가능함
		for (int j = -m; j <= m; j++) {
			// case1) i번째 원소가 A에 들어가는 경우 : i번째 원소 값만큼 더해준다
			Update(i, j, i - 1, j - arr[i], arr[i]);

			// case2) i번째 원소가 B에 들어가는 경우
			Update(i, j, i - 1, j + arr[i], 0);
			// case3) i번째 원소가 C에 들어가는 경우
			Update(i, j, i - 1, j, 0);
		}
	}
	cout << dp[n][0+OFFSET];
	
	return 0;
}