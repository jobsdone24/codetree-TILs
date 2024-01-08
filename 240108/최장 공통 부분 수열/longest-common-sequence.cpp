#include<iostream>
#include<string>
#define MAX_N 1000
using namespace std;
int sn, sm;
int dp[MAX_N + 1][MAX_N + 1];

int main() {
	string a, b;
	cin >> a >> b;
	sn = a.size();
	sm = b.size();

	//초기값 설정
	if (a[0] == b[0])dp[0][0] = 1;
	else dp[0][0] = 0;

	for (int j = 1; j < sm; j++) {
		if (dp[0][j - 1]) dp[0][j] = 1;
		else if (a[0] == b[j]) dp[0][j] = 1;
	}
	for (int i = 1; i < sn; i++) {
		if (dp[i - 1][0]) dp[i][0] = 1;
		else if (a[i] == b[0]) dp[i][0] = 1;
	}

	for (int i = 1; i < sn; i++) {
		for (int j = 1; j < sm; j++) {
			// case1) 문자가 서로 같은 경우
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[sn - 1][sm - 1];
}