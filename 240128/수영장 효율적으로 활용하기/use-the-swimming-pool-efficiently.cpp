#include<iostream>
#define MAX_N 100'000
#define MAX_T 1'440
using namespace std;

int n, m;
int t[MAX_N + 1];

bool IsPossible(int limit) {
	int lane = 1;
	int hap = t[0];
	for (int i = 1; i < n; i++) {
		//다음 레인으로 바꿔주기
		if (hap + t[i] > limit) {
			lane++;
			hap = t[i];
		}
		//기존의 레인을 사용하기
		else hap += t[i];
	}
	return lane <= m;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> t[i];
	int left = 1;
	int right = MAX_N * MAX_T;
	int dap = MAX_N * MAX_T;
	while (left <= right){
		int mid = (left + right) / 2;
		//만약 한 레인당 limit 시간보다 적게 들어올 수 있다면
		if (IsPossible(mid)) {
			//limit 시간을 더 줄이기
			right = mid - 1;
			dap = min(dap, mid);
		}
		else left = mid + 1;
	}
	cout << dap;
}