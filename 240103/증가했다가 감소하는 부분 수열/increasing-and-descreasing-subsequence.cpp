#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
int number[1004];
int dp[1004][2]; //뒤의 번호가 0일때 -> 증가하는 경우 1일때 -> 감소하는 경우
int N;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}

	for(int i=0;i<N;i++){
		//해당 값 처음 시작할 때
		dp[i][0] = 1;
		dp[i][1] = 1;

		//case1) 증가하는 경우
		for(int j=0;j<i;j++){
			if(number[i]>number[j]){
				dp[i][0] = max(dp[i][0],dp[j][0]+1);
			}
		}

		//case2) 감소하는 경우
		for(int j=0;j<i;j++){
			if(number[i]<number[j]){
				dp[i][1] = max(dp[i][1],dp[j][1]+1);
			}
		}
		//case3) 증가 -> 감소하는 경우
		dp[i][1] = max(dp[i][1], dp[i][0]);
	}
	int ans = 0;
	for(int i = 0; i < N; i++) {
		for(int j=0;j<2;j++){
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}