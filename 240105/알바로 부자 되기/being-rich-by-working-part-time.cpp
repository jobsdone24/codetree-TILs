#include<iostream>
#include<climits>

#define MAX_N 1000

using namespace std;
int dp[MAX_N + 1]; // i번째 알바를 진행했을 때 벌 수 있는 최대 돈
int N;
int price;
int arr[MAX_N][3];


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		
		//초기값 등록
		dp[i] = arr[i][2]; //i번째 일만 했을 때 벌수 있는 돈
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i][0] > arr[i][1]) {
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