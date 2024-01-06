#include<iostream>
#include<climits>
#define MAX_N 100000
using namespace std;


int elements[MAX_N + 1];
int dp[MAX_N + 1]; //dp[i] 마지막으로 i를 선택했을 때의 최대값

int main() {
	int n;
	cin >> n;


	for (int i = 1; i <= n; i++) cin >> elements[i];

	//초기값 처리
	for (int i = 0; i <= n; i++) {
		dp[i] = INT_MIN;
	}
	dp[1] = elements[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] + elements[i], elements[i]);
	}

	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}