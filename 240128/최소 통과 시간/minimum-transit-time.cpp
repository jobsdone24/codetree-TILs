#include<iostream>
#define MAX_N 100'000
using namespace std;

int n, m;
int arr[MAX_N + 1];

bool IsPossible(int x) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt += x/arr[i];
    }

	if (cnt >= n) return true;
	else return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];

	int lo = 1;
	int hi = 1e9;
	int dap = 1e9;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (IsPossible(mid)) {
			hi = mid - 1;
			dap = min(dap, mid);
		}
		else lo = mid + 1;
	}
	cout << dap;
}