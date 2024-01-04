#include<iostream>
#include<climits>

#define MAX_N 100
#define MAX_M 10000
using namespace std;

int n, m;
int elements[103];

bool dp[MAX_N+1][MAX_M+1]; //dp[i][j] -> i번째 수까지 고려했을 대 j로 만드는것이 가능하면true 아니면false

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> elements[i];
	}
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		//case 1 i번을 포함해서 j를 만드는 경우

		//case 2 i번을 포함하지 않고 j를 만드는 경우

		for(int j=0;j<=m;j++){
			if(j>=elements[i] && dp[i-1][[j-elements[i]]]) dp[i][j] = true;

			if(dp[i-1][j]) dp[i][j] = true;
		}
	}

	if(dp[n][m]) cout << "Yes";
	else cout << "No"
}