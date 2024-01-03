#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
int number[1004];
int dp[1004];
int N;

void init() {
	for (int i = 0; i < N; i++) {
		dp[i] =0;
	}
	dp[0] = 1;
}

int find(int limits) {
	init();

	//증가 수열 만들기
	for (int i = 0; i <= limits; i++) {
		for (int j = 0; j < i; j++) {
			if (number[i] > number[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] == INT_MIN) dp[i] = 1;
	}

	//감소 수열 만들기
	for (int i = limits + 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (number[i] < number[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] == INT_MIN) dp[i] = 1;
	}

	int big = 0;
	for (int i = 0; i < N; i++) {
		if (big < dp[i]) big = dp[i];
	}
	return big;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}

	int ans = 0;
	for(int i = 0; i < N; i++) {
		ans = max(ans, find(i));
	}
	cout << ans;
}