#include<iostream>
#define MAX_N 100
#define MAX_M 10000
using namespace std;

int arr[MAX_N + 1];
bool dp[MAX_N + 1][MAX_M + 1]; // dp[i][j] -> i번째 원소까지 생각했을 때 j를 만들 수 있으면 true

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	//초기값 설정
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		//i원소를 사용하고 j를 만드는 경우

		//i원소를 사용하지 않고 j를 만드는 경우
		for (int j = 0; j <= m; j++) {
			if (j >= arr[i] && dp[i - 1][j - arr[i]]) {
				dp[i][j] = true;
			}
				
			if (dp[i - 1][j]) {
				dp[i][j] = true;
			}
		}
	}

	if (dp[n][m])cout << "Yes";
	else cout << "No";

	return 0;
}