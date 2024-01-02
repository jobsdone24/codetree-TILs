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

	//초기값 설정 지나간 값중 최소값

	dp[0][0] = map[0][0];

	for (int i = 0; i < N; i++) {
		dp[i][0] = min(dp[i][0], map[i][0]);
		dp[0][i] = min(dp[0][i], map[0][i]);
	}

	//점화식 적용
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = min(max(dp[i - 1][j], dp[i][j - 1]), map[i][j]);
		}
	}

	cout << dp[N - 1][N - 1];
}