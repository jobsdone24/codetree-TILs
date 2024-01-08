#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 101;
const int MAX_M = 41;
const int INT_MIN_VAL = -1e9;  // Integer.MIN_VALUE와 유사

int n, m;
int arr[MAX_N];
int dp[MAX_N][MAX_M];

void init() {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= MAX_M; ++j) {
            dp[i][j] = 0;
        }
    }

    dp[1][arr[1] + 20]++;
    dp[1][-1 * arr[1] + 20]++;
}

void findNumCnt() {
    init();

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= MAX_M; ++j) {
            if (dp[i - 1][j] == 0) {
                continue;
            }

            if (0 <= (j - arr[i]) && (j - arr[i]) <= MAX_M) {
                dp[i][j - arr[i]] += dp[i - 1][j];
            }
            if (0 <= (j + arr[i]) && (j + arr[i]) <= MAX_M) {
                dp[i][j + arr[i]] += dp[i - 1][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    findNumCnt();

    cout << dp[n][m + 20] << '\n';

    return 0;
}