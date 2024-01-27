#include<iostream>
using namespace std;

int arr[10010];
int n, m;

bool IsPossible(int target) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += arr[i] / target;
	}
	return cnt >= m;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	//가능한 크기
	int left = 1;
	int right = 100000;
	int dap = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (IsPossible(mid)) {
			left = mid + 1;
			dap = max(dap, mid);
		}
		else right = mid - 1;
	}
	cout << dap;
}