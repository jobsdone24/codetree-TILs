#include<iostream>
using namespace std;

int n;

int IsPossible(int target) {
	int cnt = 0;
	for (int i = 1; i <= target; i++) {
		if (i % 3 == 0 || i % 5==0) continue;
		else cnt++;
		
		if (cnt > n) return 1;
	}
	if (cnt < n)return 2;
}

int main() {
	cin >> n;
	int left = 1;
	int right = 1e9;
	int dap = 1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		int num = IsPossible(mid);
		if (num == 1) right = mid - 1;
		else{
            left = mid + 1;
            dap = min(dap,mid);
		}
	}
	cout << dap;
}