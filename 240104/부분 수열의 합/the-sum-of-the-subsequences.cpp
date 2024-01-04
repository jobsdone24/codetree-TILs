#include<iostream>
#include<climits>
using namespace std;

int n, m;
int elements[103];
int dp[10003];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> elements[i];
	}

	//초기화
	for (int i = 1; i <= m; i++) {
		dp[i] = INT_MIN;
	}
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			int e = elements[i];
			if (j >= e) {
				if (dp[j - e] == INT_MIN) continue;
				dp[j] = max(dp[j], dp[j - e] + 1);
			}
		}
	}

	if (dp[m] == INT_MIN) cout << "No";
	else cout << "Yes";
}