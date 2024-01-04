#include<iostream>
using namespace std;

int dp[1003];

int main() {
	int n;
	cin >> n;
	
	//초기값 등록
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;
	dp[5] = 9;

	for (int i = 6; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 5];
		dp[i] %= 10007;
	}
	cout << dp[n];
}