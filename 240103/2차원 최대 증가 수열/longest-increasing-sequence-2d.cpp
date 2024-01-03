#include<iostream>
#include<climits>
#define MAX_M 53

using namespace std;

int map[MAX_M][MAX_M];
int dp[MAX_M][MAX_M];
int n, m;

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			dp[i][j] = INT_MIN;
		}
	}

	//초기값 설정
	dp[0][0] = 1;
	for (int t = 1; t < n; t++) {
		for (int q = 1; q < m; q++) {
			if (map[0][0] < map[t][q]) {
				dp[t][q] = max(dp[t][q], dp[0][0] + 1);
			}
		}
	}

	//점화식 적용
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++){
			//각각의 경우에 이중 for문 돌리기
			for (int t = i + 1; t < n; t++) {
				for (int q = j + 1; q < m; q++) {
					if (map[i][j] < map[t][q]) {
						dp[t][q] = max(dp[t][q], dp[i][j] + 1);
					}
				}
			}
		}
	}

	//값 출력
	int big = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (big < dp[i][j]) big = dp[i][j];
		}
	}
	cout << big;
}