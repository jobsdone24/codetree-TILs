#include<iostream>
#include<climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	int time[16] = { 0 };
	int money[16] = { 0 };
	int dp[16] = { 0 }; // k날짜 까지 일했을 때 벌 수 있는 최대 돈

	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> t >> p;
		time[i] = t;
		money[i] = p;
	}
	
	for (int i = n; i >= 1; i--) {
		//범위 안에 들어올 때
		if (i + time[i] <= n+1) {
			dp[i] = max(dp[i + 1], dp[i + time[i]] + money[i]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}