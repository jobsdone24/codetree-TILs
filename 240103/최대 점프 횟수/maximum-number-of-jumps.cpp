#include<iostream>	
#define MAX_NUM 1000
using namespace std;
int jump[MAX_NUM + 1];
int dp[MAX_NUM + 1];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int j;
		cin >> j;
		jump[i] = j;
	}

	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (j + jump[j] >= i) {
				dp[i] = max(dp[j]+1, dp[i]);
			}
		}
	}

	//결과값 출력
	int big = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > big) big = dp[i];
	}
	cout << big;
}