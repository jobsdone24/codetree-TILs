#include<iostream>
#include<math.h>
#include<climits>
#define MAX_S 100
using namespace std;

int map[103][103] = { 0 };
int dp[103][103] = { 0 };
int N;


void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = INT_MAX;
		}
	}

	dp[0][0] = map[0][0];

	for (int i = 1; i < N; i++) {
		dp[i][0] = max(dp[i - 1][0], map[i][0]);
		dp[0][i] = max(dp[0][i - 1], map[0][i]);
	}
}

int found(int limit) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] < limit) map[i][j] = INT_MAX;
		}
	}
	init();
	
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			dp[i][j] = max(min(dp[i - 1][j], dp[i][j - 1]), map[i][j]);
		}
	}
	return dp[N - 1][N - 1];
}

int main() {
	cin >> N;

	int big = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > big) big = map[i][j];
		}
	}

	// Solve;
	int ans = INT_MAX;

	//최솟값을 각각 비교 후 최소가 되는 값 찾기
	for (int lower_bound = 1; lower_bound <= big; lower_bound++) {
		int upper_bound = found(lower_bound);

		//만약 지나칠 수 없는 곳을 지나쳤다면 넘어가기
		if (upper_bound == INT_MAX)continue;
		ans = min(ans, upper_bound - lower_bound);
	}
	cout << ans;
}