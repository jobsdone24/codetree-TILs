#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 101;
const int MAX_M = 41;

int n, m;
int arr[MAX_N];
long long dp[MAX_N][MAX_M];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    dp[1][arr[1] + 20]=1;
    dp[1][-1 * arr[1] + 20]=1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < MAX_M; ++j) {
            if (dp[i - 1][j] == 0) {
                continue;
            }

            if (0 <= (j - arr[i]) && (j - arr[i]) < MAX_M) {
                dp[i][j - arr[i]] += dp[i - 1][j];
            }
            if (0 <= (j + arr[i]) && (j + arr[i]) < MAX_M) {
                dp[i][j + arr[i]] += dp[i - 1][j];
            }
        }
    }

    cout << dp[n][m + 20];

    return 0;
}