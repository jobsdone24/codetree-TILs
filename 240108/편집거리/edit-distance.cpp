#include<iostream>
#include<string>
#define MAX_N 1000
using namespace std;
int sn, sm;
int dp[MAX_N + 1][MAX_N + 1]; //dp[i][j] A문자열을 i, B문자열을 j까지 고려하였을 때 최소 편집 거리

int main() {
	string a, b;
	cin >> a >> b;
	sn = a.size();
	sm = b.size();
	int flaga = 0;
	int flagb = 0;
	//초기값 설정
	if (a[0] == b[0]) {
		dp[0][0] = 0;
		flaga = 1;
		flagb = 1;
	}
	else dp[0][0] = 1;

	for (int j = 1; j < sm; j++) {
		if (a[0] == b[j] && flaga == 0) {
			dp[0][j] = dp[0][j - 1];
			flaga = 1;
		}
		else dp[0][j] = dp[0][j - 1] + 1;
	}

	for (int i = 1; i < sn; i++) {
		if (a[i] == b[0] && flagb == 0) {
			dp[i][0] = dp[i - 1][0];
			flagb = 1;
		}
		else dp[i][0] = dp[i - 1][0] + 1;
	}

	for (int i = 1; i < sn; i++) {
		for (int j = 1; j < sm; j++) {
			// case1) 문자가 서로 같은 경우 편집거리는 dp[i-1][j-1]과 같다.
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i-1][j-1],min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
	}
	cout << dp[sn - 1][sm - 1];
}