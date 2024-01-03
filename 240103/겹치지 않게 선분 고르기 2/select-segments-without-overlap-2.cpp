#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> save;

	int dp[1001] = { 0 }; //맨 마지막값이 k일때 최대로 선택한 수
	for (int i = 0; i < n; i++) {
		int f, l;
		cin >> f >> l;
		save.push_back({ l,f });
	}

	for (int i = 1; i <= 1000; i++) dp[i] = INT_MIN;
	
	sort(save.begin(), save.end());
	int last = save[0].first;
	dp[last] = 1;
	int size = save.size();

	for (int i = 1; i < size; i++) {
		int start = save[i].second;
		int end = save[i].first;
		for (int j = 0; j < i; j++) {
			int s = save[j].second;
			int e = save[j].first;
			if (e < start) {
				dp[end] = max(dp[e] + 1, dp[end]);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= 1000; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}