#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 1001
using namespace std;

int main() {
	int n;
	int x[MAX], y[MAX];
	int ans = INT_MAX;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 1; i <= n-1; i++) {
		int dist = 0; 
		int prev_idx = 0;
		for (int j = 1; j < n; j++) {
			if (j == i) continue;
			dist += abs(x[prev_idx] - x[j]) + abs(y[prev_idx] - y[j]);
			prev_idx = j;
		}
		ans = min(ans, dist);
	}
	cout << ans;
}