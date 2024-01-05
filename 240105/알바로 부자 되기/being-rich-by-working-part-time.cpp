#include<iostream>
#include<climits>
#define MAX_N 1000
using namespace std;

typedef struct {
	int s, e, p;
}S;

int dp[MAX_N + 1]; // dp[i] -> i번째를 마지막으로 진행 했을 때 수익의 최대값
int N;
S info[MAX_N + 1];

void Initialize() {
	for (int i = 0; i <= N; i++) {
		dp[i] = INT_MIN;
	}
	dp[0] = 0;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int s, e, p;
		cin >> s >> e >> p;
		info[i] = { s,e,p };
	}

	//초기화
	Initialize();

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (info[j].e < info[i].s) {
				dp[i] = max(dp[i], dp[j] + info[i].p);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= N; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}