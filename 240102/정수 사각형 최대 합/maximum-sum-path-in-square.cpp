#include<iostream>
#include<math.h>
using namespace std;

int N;
int map[102][102] = { 0 };
int dp[102][102] = { 0 };

void show() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dp[i][j] << " ";
		}cout << "\n";
	}cout << "\n";
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	//초기값 대입
	dp[0][0] = map[0][0];

	for (int i = 1; i < N; i++) {
		dp[i][0] += map[i][0] + dp[i - 1][0];
		dp[0][i] += map[0][i] + dp[0][i-1];
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])+map[i][j];
		}
	}
	
	//최대값 출력
	int big = 0;

	for (int i = 0; i < N; i++) {
		if (dp[N - 1][i] > big)big = dp[N - 1][i];
	}
	cout << big;
}