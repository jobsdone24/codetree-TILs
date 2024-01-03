#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v;
	int N;
	int dp[1004] = {};
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	dp[0] = 1;
	for (int i = 1; i < v.size(); i++) {
		int big = 0;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && dp[j] > big)big = dp[j];
		}
		//큰게 없다면 처음부터 시작
		if (big == 0) dp[i] = 1;
		else dp[i] = big + 1;
	}
	
	int dap = 0;
	for (int i = 0; i < v.size(); i++) {
		if (dap < dp[i])dap = dp[i];
	}

	cout << dap;
}