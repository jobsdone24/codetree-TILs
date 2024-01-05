#include<iostream>
#include<climits>

#define MAX_N 1000

using namespace std;
int dp[MAX_N + 1]; // 마지막으로 고른 알바가 i번째 일때 벌 수 있는 최대 돈
int N;
int price;
int arr[MAX_N][3];


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	//초기값 등록
	for(int i=0;i<=N;i++){
		dp[i] = INT_MIN;
	}

	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i][0] > arr[j][1]) {
				dp[i] = max(dp[i], dp[j] + arr[i][2]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}