#include<iostream>
#include<climits>
#define MAX_N 200
#define MAX_M 200
using namespace std;

/*
	언제가 동일한 경우일까?
	dp[i] ->  i번째 날에 마지막으로 고른 옷이 같고, 그때까지의 아름다움이 같다면 같은 상황이다.
	만약 마지막에 고른 옷이 다르다면 화려함도 다르다

	dp[i][j] i번째 날까지 고려했을 때 선택한 옷이 j인 경우 이때 아름다움의 최대값
*/

int info[MAX_N + 1][3];
int dp[MAX_M+ 1][MAX_N+1];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> info[i][0] >> info[i][1] >> info[i][2]; // (s, e, v)
	}
	
	//초기화
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][i] = INT_MIN;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if(info[i][0]==1) dp[1][i] = 0;
	}

	for (int i = 2; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int start = info[j][0];
			int end = info[j][1];
			int val = info[j][2];
			if (i >= start && i <= end) {
				for (int k = 1; k <= n; k++) {
					int ks = info[k][0];
					int ke = info[k][1];
					int kv = info[k][2];
					if (i - 1 >= ks && i - 1 <= ke) {
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(info[k][2] - info[j][2]));
					}
				}
			}
		}
	}

	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[m][i]);
	}
	cout << ans;
}