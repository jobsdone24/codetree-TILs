#include<iostream>
#include<climits>
using namespace std;

int coin[104];
int dp[10004];
int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> coin[i];
	}

	//table 초기화
	for (int i = 0; i < M; i++) {
		dp[i] = INT_MIN;
	}
	dp[0] = 0;

	//dp[k] k원을 모을 때 고를 때 있는 최대 동전

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			int c = coin[j];
			if (i>=c) {
				if (dp[i -c]  == INT_MIN) continue;
				dp[i] = max(dp[i], dp[i - c] + 1);
			}
		}
	}
	if (dp[M] == INT_MIN) cout << -1;
	else cout << dp[M];
}