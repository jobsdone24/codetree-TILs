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
	dp[0][N - 1] = map[0][N - 1];

	for (int i = N - 2; i >= 0; i--) {
		dp[0][i] = dp[0][i + 1] + map[0][i];
	}

	for (int i = 1; i <N ; i++) {
		dp[i][N - 1] = dp[i - 1][N - 1] + map[i][N - 1];
	}

	//점화식 적용
	for (int i = 1; i < N; i++) {
		for (int j = N - 2; j >= 0; j--) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j + 1]) + map[i][j];
		}
	}
	cout << dp[N - 1][0];
}